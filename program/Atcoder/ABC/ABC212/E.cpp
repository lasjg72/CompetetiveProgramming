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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll> dp(n, 0);
    dp[0] = 1;
    for(int i = 0; i < k; i++){
        vector<ll> p(n);
        swap(p, dp);
        ll tot = 0;
        for(int j = 0; j < n; j++){
            tot += p[j];
            tot %= mod;
        }
        for(int j = 0; j < n; j++){
            dp[j] = tot;
            for(int u : g[j]){
                dp[j] -= p[u];
                dp[j] = (dp[j]+mod)%mod;
            }
            dp[j] -= p[j];
            dp[j] = (dp[j]+mod)%mod;
        }
    }
    cout << dp[0] << endl;
    return 0;
}