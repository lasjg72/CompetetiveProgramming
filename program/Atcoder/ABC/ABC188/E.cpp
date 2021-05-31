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
vector<ll> a;
ll dp[200005];
vector<bool> used;

// void dfs(int x){
//     for(int to : g[x]){
//         dp[to] = min(dp[to], dp[x]);
//         dp[to] = min(dp[to], a[x]);
//         if(used[to]) continue;
//         used[to] = true;
//         dfs(to);
//     }
// }

int main()
{
    int n, m;
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = 1001001001;
    }
    g.resize(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
    }
    used.resize(n);
    // for(int i = 0; i < n; i++){
    //     if(used[i]) continue;
    //     else{
    //         used[i] = true;
    //         dfs(i);
    //     }
    // }
    ll ans = -1001001001;
    for(int i = 0; i < n; i++){
        if(dp[i] != 1001001001) ans = max(ans, a[i]-dp[i]);
        for(int to : g[i]){
            dp[to] = min(dp[to], dp[i]);
            dp[to] = min(dp[to], a[i]);
        }
    }
    // for(int i = 0; i < n; i++){
    //     if(dp[i] == 1001001001) continue;
    //     ans = max(ans, a[i]-dp[i]);
    // }
    cout << ans << endl;
    return 0;
}