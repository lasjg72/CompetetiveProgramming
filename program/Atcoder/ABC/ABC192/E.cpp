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

struct E{
    ll to;
    ll co;
    ll k;
    //E(ll to = 0, ll co = 0) : to(to), co(co){}
    E(ll to, ll co, ll k){
        this->to = to;
        this->co = co;
        this->k = k;
    }
};

int main()
{
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    x--; y--;
    vector<vector<E>> g(n);
    vector<ll> k(n);
    for(ll i = 0; i < m; i++){
        ll a, b, c, k;
        cin >> a >> b >> c >> k;
        a--; b--;
        g[a].emplace_back(b, c, k);
        g[b].emplace_back(a, c, k);
    }
    ll INF = 1001001001001001001;

    vector<ll> dist(n, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
    que.emplace(0, x);
    dist[x] = 0;
    while(!que.empty()){
        ll nv = que.top().second;
        ll nc = que.top().first;
        que.pop();
        if(dist[nv] != nc) continue;
        for(E e : g[nv]){
            ll tmp = nc;
            //cout << "tmp: " << nc << endl;
            if(tmp % e.k != 0){
                tmp = tmp + e.k-tmp%e.k;
            }
            //cout << "tmp: " << tmp << "e.k: " << e.k << endl;
            if(dist[e.to] <= tmp+e.co)continue;
            dist[e.to] = tmp+e.co;
            que.emplace(tmp+e.co, e.to);
            //cout << tmp+e.co << " to: " << e.to << endl;
        }
    }
    ll ans = dist[y];
    if(ans == INF) ans = -1;
    cout << ans << endl;
    // for(ll i = 0; i < n; i++){
    //     cout << "i: " << i << endl;
    //     cout << dist[i] << endl;
    // }
    return 0;
}