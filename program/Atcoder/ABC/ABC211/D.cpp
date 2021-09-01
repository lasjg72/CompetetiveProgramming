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
const int mod = 1e9+7;
const ll INF = 1001001001001001001;
typedef pair<ll, int> Edge;

vector<vector<Edge>> g;
vector<ll> dist, num;

int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    dist.resize(n, INF);
    num.resize(n, 0);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(Edge(1, b));
        g[b].push_back(Edge(1, a));
    }
    dist[0] = 0;
    num[0] = 1;
    priority_queue<Edge, vector<Edge>, greater<Edge> > que;
    que.push(Edge(0, 0));
    while (!que.empty()) {
        ll now = que.top().first;
        int cur = que.top().second;
        que.pop();
        if (dist[cur] < now) continue;
        for (auto e : g[cur]) {
            if (dist[e.second] > dist[cur] + e.first) {
                dist[e.second] = dist[cur] + e.first;
                num[e.second] = num[cur];
                que.push(Edge(dist[e.second], e.second));
            }
            else if (dist[e.second] == dist[cur] + e.first) {
                num[e.second] += num[cur];
                num[e.second] %= mod;
            }
        }
    }
    cout << num[n-1] << endl;
    return 0;
}