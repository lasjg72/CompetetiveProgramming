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
vector<vector<int>> g;
vector<int> dist;
vector<bool> used;
const int INF = 1001001001;

void dfs(int n = 0, int p = -1, int d = 0){
    dist[n] = d;
    for(int to : g[n]){
        if(to == p) continue;
        dfs(to, n, d+1);
    }
    return;
}

int main()
{
    int n, q;
    cin >> n >> q;
    g.resize(n);
    dist.resize(n, INF);
    used.resize(n, false);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs();
    while(q--){
        int c, d;
        cin >> c >> d;
        c--; d--;
        //cout << dist[c] << " " << dist[d] << endl;
        if(abs(dist[c]-dist[d])%2 == 0){
            cout << "Town" << endl;
        }else{
            cout << "Road" << endl;
        }
    }
    return 0;
}