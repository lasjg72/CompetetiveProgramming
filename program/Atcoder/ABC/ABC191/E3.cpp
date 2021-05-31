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

struct Edge{
    int to;
    int co;
    Edge(int to, int co) : to(to), co(co){}
};

const int INF = 1001001001;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> g(n);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(b, c);
    }
    for(int sv = 0; sv < n; sv++){
        vector<int> dist(n, INF);
        priority_queue<P, vector<P>, greater<P>> q;
        q.push({0, sv});
        while(!q.empty()){
            P p = q.top(); q.pop();
            int s = p.second;
            int now = p.first;
            if(s != sv && dist[s] != now) continue;
            for(Edge e : g[s]){
                if(dist[e.to] >= now + e.co){
                    dist[e.to] = now + e.co;
                    q.push({dist[e.to], e.to});
                }
            }
        }
        if(dist[sv] == INF) cout << -1 << endl;
        else cout << dist[sv] << endl;
    }
    return 0;
}