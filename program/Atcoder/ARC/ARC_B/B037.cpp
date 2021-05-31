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
vector<bool> used;
bool circle;

void dfs(int x, int p){
    for(int to : g[x]){
        if(to == p) continue;
        if(used[to]) circle = true;
        else{
            used[to] = true;
            dfs(to, x);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n, false);
    for(int i = 0; i < m; i++){

        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        circle = false;
        if(used[i]) continue;
        used[i] = true;
        dfs(i, -1);
        if(!circle) ans++;
    }
    cout << ans << endl;
    return 0;
}