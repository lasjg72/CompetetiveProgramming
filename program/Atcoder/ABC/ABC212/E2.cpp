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
const int mod = 998244353;


int main()
{
    int n, m, K;
    cin >> n >> m >> K;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<vector<int>> dp(K+1, vector<int>(n));
    dp[0][0] = 1;
    for(int k = 0; k < K; k++){
        ll tot = 0;
        for(int i = 0; i < n; i++){
            tot += dp[k][i];
            tot %= mod;
        }
        for(int i = 0; i < n; i++){
            dp[k+1][i] = tot;
            for(int u : g[i]){
                dp[k+1][i] -= dp[k][u];
                dp[k+1][i] = (dp[k+1][i]+mod)%mod;
            }
            dp[k+1][i] -= dp[k][i];
            dp[k+1][i] = (dp[k+1][i]+mod)%mod;
        }
    }
    cout << dp[K][0] << endl;
    return 0;
}