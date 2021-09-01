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

struct Edge{
    int to, co;
    Edge(int to, int co):to(to), co(co){};
};

const int INF = 1001001001;

vector<vector<Edge>> g;
vector<int> dist;

void dfs(int u, int now = 0){
    for(Edge e : g[u]){
        int v = e.to;
        int cost = e.co;
        //cout << "v: " << v << " dist: " << dist[v] << endl;
        if(dist[v] == INF){
            dist[v] = dist[u] + cost;
            now = dist[u] + cost;
            dfs(v);
        }else if(dist[v] != INF && dist[v] != dist[u]+cost){
            cout << "No" << endl;
            exit(0);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    dist.resize(n, INF);
    for(int i = 0; i < m; i++){
        int l, r, d;
        cin >> l >> r >> d;
        l--; r--;
        g[l].emplace_back(r, d);
        g[r].emplace_back(l, -d);
    }
    for(int i = 0; i < n; i++){
        if(dist[i] == INF){
            dist[i] = 0;
            dfs(i);
        }
    }
    cout << "Yes" << endl;
    return 0;
}
