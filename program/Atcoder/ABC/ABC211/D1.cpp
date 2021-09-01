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

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int INF = 1001001001;
    vector<int> dist(n, INF);
    queue<int> q;
    q.push(0);
    vector<int> vs;
    dist[0] = 0;
    while(!q.empty()){
        int v = q.front(); q.pop();
        vs.push_back(v);
        for(int u : g[v]){
            if(dist[u] != INF) continue;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }
    vector<ll> ans(n, 0);
    ans[0] = 1;
    for(int u : vs){
        for(int t : g[u]){
            if(dist[u] == dist[t] + 1){
                ans[u] += ans[t];
                ans[u] %= mod;
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     cout << "i: " << i << " ans: " << ans[i] << endl;
    // }
    cout << ans[n-1] << endl;
    return 0;
}