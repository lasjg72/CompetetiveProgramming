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
    int n;
    cin >> n;
    vector<double> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    double dp[n+1][n+1];
    dp[0][0] = 1;
    for(int i = 1; i < n+1; i++){
        for(int j = 0; j < i+1; j++){
            if(j > 0) dp[i][j] = dp[i-1][j-1]*p[i-1] + dp[i-1][j]*(1-p[i-1]);
            else dp[i][j] = dp[i-1][j]*(1-p[i-1]);
        }
    }
    double ans = 0;
    for(int i = (n+1)/2; i < n+1; i++){
        ans += dp[n][i];
    }
    printf("%.10f\n", ans);
    return 0;
}