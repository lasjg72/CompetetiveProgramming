#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cassert>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

struct G{
    ll to;
    ll co1;
    ll co2;
    G(ll to, ll co1, ll co2) : to(to), co1(co1), co2(co2){}
};

int main()
{
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--;
    vector<vector<G>> g(n);
    for(ll i = 0; i < m; i++){
        ll u, v, a, b;
        cin >> u >> v >> a >> b;
        u--; v--;
        g[u].emplace_back(v, a, b);
        g[v].emplace_back(u, a, b);
    }
    const ll INF = 1e15;
    ll money = 1e15;

    priority_queue<P, vector<P>, greater<P>> en;
    en.emplace(0, s);
    vector<ll> dist(n, INF);
    vector<ll> ans_en(n, INF);
    dist[s] = 0;
    ans_en[s] = 0;
    while(!en.empty()){
        ll nv = en.top().second; 
        ll nc = en.top().first;
        en.pop();
        if(dist[nv] != nc) continue;
        for(G e : g[nv]){
            if(dist[e.to] <= e.co1+nc) continue;
            dist[e.to] = e.co1+nc;
            ans_en[e.to] = e.co1+nc;
            en.emplace(e.co1+nc, e.to);
        }
    }

    priority_queue<P, vector<P>, greater<P>> snuk;
    snuk.emplace(0, t);
    vector<ll> dist_snuk(n, INF);
    vector<ll> ans_snuk(n, INF);
    dist_snuk[t] = 0;
    ans_snuk[t] = 0;
    while(!snuk.empty()){
        ll nv = snuk.top().second; 
        ll nc = snuk.top().first;
        snuk.pop();
        if(dist_snuk[nv] != nc) continue;
        for(G e : g[nv]){
            if(dist_snuk[e.to] <= e.co2+nc) continue;
            dist_snuk[e.to] = e.co2+nc;
            ans_snuk[e.to] = e.co2+nc;
            snuk.emplace(e.co2+nc, e.to);
        }
    }

    vector<ll> ans(n, 0);
    ll mx = 0;
    for(ll i = n-1; i >= 0; i--){
        ll nans = dist[i]+dist_snuk[i];
        mx = max(money-nans, mx);
        if(i != n-1) ans[i] = max(ans[i+1], mx);
        else ans[i] = mx;
        //cout << "i: " << i << " dist[i]: " << dist[i] << " dist_snuk[i]: " << dist_snuk[i] << endl;
        //ans[i] = max(ans[i], money - nans);
    }
    for(ll i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}