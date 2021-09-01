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
ll dp[5005][5005];
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
    dp[0][0] = 1;
    for(int k = 1; k <= K; k++){
        ll tot = 0;
        for(int i = 0; i < n; i++){
            tot += dp[k-1][i];
            tot %= mod;
        }
        for(int i = 0; i < n; i++){
            dp[k][i] = tot;
            for(int to : g[i]){
                dp[k][i] -= dp[k-1][to];
                dp[k][i] = (dp[k][i]+mod)%mod;
            }
            dp[k][i] -= dp[k-1][i];
            dp[k][i] = (dp[k][i]+mod)%mod;
        }
    }
    cout << dp[K][0] << endl;
    return 0;
}