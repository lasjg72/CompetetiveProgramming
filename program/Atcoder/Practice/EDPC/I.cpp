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

// dp[i][j]: i枚目を投げた時にj枚が表である確率　dp[i][j] = dp[i-1][j]+dp[i-1][j-1]*p[i];
double dp[3000][3000];

int main()
{
    int n;
    cin >> n;
    vector<double> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(j-1 < 0) dp[i][j] = dp[i-1][j]*(1-p[i-1]);
            else dp[i][j] = dp[i-1][j]*(1-p[i-1])+dp[i-1][j-1]*p[i-1];
        }
    }
    double ans = 0;
    for(int i = n/2+1; i <= n; i++) ans += dp[n][i];
    printf("%.10f\n", ans);

    return 0;
}