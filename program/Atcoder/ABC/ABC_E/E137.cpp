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

struct edge{
    int to;
    int cost;
    edge(int to, int cost):to(to), cost(cost){};
};
bool reachFrom1[2505], reachFromn[2505], ok[2505];

vector<vector<edge>> g;
vector<vector<int>> rto;

void dfs(int u){
    //cout << u << endl;
    if(reachFrom1[u]) return ;
    reachFrom1[u] = true;
    for(edge e : g[u]){
        int v = e.to;
        dfs(v);
    }
}

void rdfs(int u){
    if(reachFromn[u]) return ;
    reachFromn[u] = true;
    for(int v : rto[u]){
        rdfs(v);
    }
}
int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    g.resize(n);
    rto.resize(n);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        c -= p;
        c *= -1;
        g[a].emplace_back(b, c);
        rto[b].push_back(a);
    }
    dfs(0);
    rdfs(n-1);
    for(int i = 0; i < n; i++) ok[i] = reachFrom1[i]&reachFromn[i];
    const int INF = 1001001001;
    vector<ll> dist(n, INF);
    int cnt = 0;
    dist[0] = 0;
    while(cnt <= n){
        bool update = true;
        for(int i = 0; i < n; i++){
            
            if(dist[i] == INF) continue;
            for(edge e : g[i]){
                if(!ok[i]) continue;
                if(!ok[e.to]) continue;
                if(dist[e.to] > dist[i]+e.cost){
                    
                    dist[e.to] = dist[i]+e.cost;
                    //cout << "i: " << i << " e.to: " << e.to << " dist: " << dist[e.to] << endl;
                    update = false;
                }
            }
        }
        cnt++;
        if(update) break;
    }
    if(cnt > n){
        cout << -1 << endl;
    }else{
        cout << max(0LL, -dist[n-1]) << endl;
    }
    return 0;
}