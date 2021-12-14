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
    ll cost;
    edge(int to, ll cost):to(to), cost(cost){};
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(n);
    for(int i = 0; i < m; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        c *= -1;
        g[a].emplace_back(b, c);
    }
    const ll INF = 1e18;
    vector<ll> dist(n, INF);
    dist[0] = 0;
    int cnt = 0;
    while(cnt <= n){
        bool update = true;
        for(int i = 0; i < n; i++){
            for(edge e: g[i]){
                int v = e.to;
                if(dist[i] != INF && dist[e.to] > dist[i] + e.cost){
                    dist[e.to] = dist[i] + e.cost;
                    update = false;
                }
            }
        }
        cnt++;
        if(!update && cnt == n+1){
            cout << "inf" << endl;
            return 0;
        }
        if(update) break;
    }
    cout << -dist[n-1] << endl;
    return 0;
}