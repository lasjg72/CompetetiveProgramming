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
int dp[100005], ans;

int dfs(int n){
    if(g[n].size() == 0) return 0;
    for(int to : g[n]){
        if(used[to]){
            dp[n] = max(dp[n], dp[to]+1);
            continue;    
        }
        used[to] = true;
        dp[n] = max(dp[n], dfs(to)+1);
    }
    ans = max(ans, dp[n]);
    return dp[n];
}

int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n, false);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
    }
    for(int i = 0; i < n; i++){
        if(!used[i]) dfs(i);
    }
    cout << ans << endl;
    return 0;
}