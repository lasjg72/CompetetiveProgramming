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

struct Edge {
    int to;
    int co;
    Edge(int to, int co) : to(to), co(co){}
};

const int INF = 1001001001;

int main()
{
    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<Edge>> g(n);
    vector<int> dist(n, INF);
    for(int i = 0; i < m; i++){
        int s, t, d;
        cin >> s >> t >> d;
        g[s].emplace_back(t, d);
    }
    priority_queue<P, vector<P>, greater<P>> q;
    q.push({0, r});
    dist[r] = 0;
    while(!q.empty()){
        P p = q.top(); q.pop();
        int s = p.second;
        for(Edge e : g[s]){
            if(dist[e.to] >= dist[s] + e.co){
                dist[e.to] = dist[s] + e.co;
                q.push({dist[e.to], e.to});
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
    return 0;
}