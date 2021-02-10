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

int dist[100005][3];
const int INF = 1001001001;

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i< n; i++){
        for(int j = 0; j < 3; j++){
            dist[i][j] = INF;
        }
    }
    vector<vector<int>> to(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--; 
        to[a].push_back(b);
    }
    queue<pair<int, int>> q;
    int s, t;
    cin >> s >> t;
    s--; t--;
    q.push({s, 0});
    dist[s][0] = 0;
    while(!q.empty()){
        int v = q.front().first;
        int l = q.front().second;
        q.pop();
        for(int u : to[v]){
            int nl = (l+1)%3;
            if(dist[u][nl] != INF) continue;
            dist[u][nl] = dist[v][l] + 1;
            q.push({u, nl});
        }
    }
    int ans = dist[t][0];
    if(dist[t][0] == INF) ans = -1;
    else ans /= 3;
    cout << ans << endl;
    return 0;
}