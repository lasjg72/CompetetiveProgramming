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
    ll c;
    ll d;
    //E(ll to = 0, ll co = 0) : to(to), co(co){}
    E(ll to, ll c, ll d){
        this->to = to;
        this->c = c;
        this->d = d;
    }
};

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<E>> g(n);
    for(ll i = 0; i < m; i++){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--;
        if(a == b) continue;
        g[a].emplace_back(b, c, d);
        g[b].emplace_back(a, c, d);
    }
    ll INF = 1001001001001001001;

    vector<ll> dist(n+1, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
    que.emplace(0, 0);
    dist[0] = 0;
    while(!que.empty()){
        ll nv = que.top().second;
        ll nc = que.top().first;
        que.pop();
        if(dist[nv] != nc) continue;
        for(E e : g[nv]){
            ll tmp;
            if((nc+1)*(nc+1) > e.d){
                tmp = nc+e.c+e.d/(nc+1);
            }else{
                ll now = (ll)sqrt(e.d);
                if(now == 0){
                    tmp = e.c+e.d;
                }else{
                    tmp = now-1+e.c+e.d/now;
                }
                tmp = min(tmp, now+e.c+e.d/(now+1));
                tmp = min(tmp, now+1+e.c+e.d/(now+2));
                if(now-2 <= -1) tmp = min(tmp, now-2+e.c+e.d/(now-1));
                if(now-3 <= -1) tmp = min(tmp, now-3+e.c+e.d/(now-2));
            }
            if(dist[e.to] <= tmp) continue;
            dist[e.to] = tmp;
            que.emplace(tmp, e.to);
        }
    }
    ll ans = dist[n-1];
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}