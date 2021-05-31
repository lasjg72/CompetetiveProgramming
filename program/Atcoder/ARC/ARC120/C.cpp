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
    int n, a;
    cin >> n >> a;
    vector<int> x(n);
    int X = 0;
    for(int i = 0; i < n; i++){
        cin >> x[i];
        x[i] -= a;
        X = max(X, abs(x[i]));
    }
    vector<vector<ll>> dp(n+1, vector<ll>(2*n*X+1, 0));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= 2*n*X; j++){
            
            if(i == 0 && j == n*X) dp[i][j] = 1;
            else if(i-1 >= 0 && j+x[i-1] <= 2*n*X && 0 <= j+x[i-1]) dp[i][j+x[i-1]] = dp[i-1][j+x[i-1]] + dp[i-1][j];
            else if(i-1 >= 0 && (j+x[i-1] > 2*n*X || j+x[i-1] < 0)) dp[i][j] = dp[i-1][j];
            else dp[i][j] = 0;
            //cout << "i, j: " << i << ", " << j << " dp[i][j]:" << dp[i][j] << endl;
        }
    }
    cout << dp[n][n*X]-1 << endl;
    return 0;
}