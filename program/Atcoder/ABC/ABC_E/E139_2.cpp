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
vector<vector<int>> id;
vector<bool> used, finished;
vector<int> dp;

int toId(int i, int j){
    if(i > j) swap(i, j);
    return id[i][j];
}

int dfs(int v){
    if(used[v]) {
        if(!finished[v]) return -1;
        return dp[v];
    }
    used[v] = true;
    //finished[v] = true;
    for(int u : g[v]){
        int res = dfs(u);
        if(res == -1) return -1;
        dp[v] = max(dp[v], res+1);
    }
    finished[v] = true;
    return dp[v];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n-1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    g.resize(n*n);
    id.resize(n*n);
    used.resize(n*n, false);
    dp.resize(n*n, 0);
    finished.resize(n*n, false);
    for(int i = 0; i < n; i++){
        id[i].resize(n);
    }
    int v = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i < j) id[i][j] = v++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            a[i][j] = toId(i, a[i][j]);
        }
        for(int j = 0; j < n-2; j++){
            g[a[i][j+1]].push_back(a[i][j]);
        }
    }
    int ans = 0;
    for(int i = 0; i < v; i++){
        int res = dfs(i);
        if(res == -1){
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, res);
    }
    cout << ans+1 << endl;
    return 0;
}