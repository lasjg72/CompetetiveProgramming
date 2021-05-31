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
ll dp[105][100005];

int main()
{
    int n, W;
    cin >> n >> W;
    vector<ll> w(n+1, 0), v(n+1, 0);
    for(int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= W; j++){
            if(j-w[i] < 0) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]]+v[i]);
            // cout << "i: " << i << "j: " << j << endl;
            // cout << "dp: " << dp[i][j] << endl;
        }
    }
    cout << dp[n][W] << endl;
    return 0;
}