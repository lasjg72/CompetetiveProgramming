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
int dp[3][100005];

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(3, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> a[j][i];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++){
            dp[j][i] = max(dp[j][i], dp[(j+1)%3][i-1]+a[j][i-1]);
            dp[j][i] = max(dp[j][i], dp[(j+2)%3][i-1]+a[j][i-1]);
        }
    }
    cout << max(dp[0][n], max(dp[1][n], dp[2][n])) << endl;
    return 0;
}