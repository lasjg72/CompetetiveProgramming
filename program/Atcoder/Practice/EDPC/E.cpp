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

// dp[i][j]: i番目までの品物の中で、価値jを達成する際の最小の重み
ll dp[101][100005];
const int INF = 1001001001;

int main()
{
    int n, W;
    cin >> n >> W;
    vector<ll> w(n), v(n);
    for(int i = 0; i < n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= 100000; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= 100000; j++){
            if(j-v[i] >= 0) dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]]+w[i]);
            else dp[i+1][j] = dp[i][j];
        }
    }
    for(int i = 100000; i >= 0; i--){
        if(dp[n][i] <= W) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}