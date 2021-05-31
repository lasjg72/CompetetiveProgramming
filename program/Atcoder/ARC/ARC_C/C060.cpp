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

ll dp[51][51][3050];

int main()
{
    int n, a;
    cin >> n >> a;
    vector<int> x(n);
    int mx = 0;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        mx = max(mx, x[i]);
    }
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            for(int k = 0; k <= 2500; k++){
                dp[i+1][j+1][k+x[i]] += dp[i][j][k];
                dp[i+1][j][k] += dp[i][j][k];
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) ans += dp[n][i][i*a];
    cout << ans << endl;
    return 0;
}