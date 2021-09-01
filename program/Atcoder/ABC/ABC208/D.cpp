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
using P = pair<int, int>;

struct edge{
    int to;
    int cost;
    edge(int to, int cost): to(to), cost(cost){};
};

const int INF = 1001001001;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(n);
    vector<vector<int>> d(n, vector<int>(n, INF));
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(b, c);
        d[a][b] = c;
    }
    ll ans = 0;
    for(int k = n-1; k >= 0; k--){
        for(int s = 0; s < n; s++){
            for(int t = 0; t < n; t++){
                priority_queue<P, vector<P>, greater<P>> q;
                //vector<vector<int>> dist(n, vector<int>(n, INF));
                vector<int> dist(n, INF);
                dist[s] = 0;
                q.emplace(dist[s], s);
                while(!q.empty()){
                    P p = q.top();
                    q.pop();
                    int v = p.second;
                    if (dist[v] < p.first) {  
                        continue;
                    }
                    for (auto &e : g[v]) {
                        if(e.to > k && e.to != t) continue;
                        if (dist[e.to] > dist[v] + e.cost) {
                            dist[e.to] = dist[v] + e.cost;
                            q.emplace(dist[e.to], e.to);
                        }
                    }
                }
                if(dist[t] != INF) ans += dist[t];
            }
        }
    }
    cout << ans << endl;
    return 0;
}