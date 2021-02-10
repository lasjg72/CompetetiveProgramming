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

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> to(n);
    vector<int> c(m);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        cin >> c[i];
        to[a].push_back({b, c[i]});
    }
    queue<int> q;
    
    for(int i = 0; i < n; i++){
        vector<int> dist(n, -1);
        vector<bool> visit(n, false);
        int ans = 1e9;
        q.push(i);
        while(!q.empty()){
            int now = q.front(); q.pop();
            for(int t = 0; t < to[now].size(); t++){
                int x = to[now][t].first;
                if(x == now) {
                    if(dist[x] == -1){ 
                        dist[x] = to[now][t].second;
                        continue;
                    }else {
                        dist[x] = min(dist[x], to[now][t].second + dist[now]); 
                        continue;
                    }
                }
                q.push(x);
                if(dist[x]==-1) {
                    dist[x] = to[now][t].second;
                }else {
                    dist[x] = min(dist[x], to[now][t].second + dist[now]);
                }
            }
        }
        cout << dist[i] << endl;
    }
    return 0;
}