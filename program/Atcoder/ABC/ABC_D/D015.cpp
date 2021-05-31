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

int dp[10005][55][55];

int main()
{
    int w, n, K;
    cin >> w >> n >> K;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    int ans = 0;
    for(int i = 0; i <= w; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= K; k++){
                if(i-a[j-1] >= 0) dp[i][j][k] = max(dp[i][j-1][k], dp[i-a[j-1]][j-1][k-1]+b[j-1]);
                else dp[i][j][k] = dp[i][j-1][k];
            }
        }
    }
    cout << dp[w][n][K] << endl;
    return 0;
}