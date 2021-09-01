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
int dp[105][100005];

int main()
{
    int n, W;
    cin >> n >> W;
    vector<int> v(n), w(n);
    for(int i = 0; i < n; i++){
        cin >> v[i] >> w[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= W; j++){
            if(j-w[i] >= 0) dp[i+1][j] = max(dp[i][j], dp[i+1][j-w[i]]+v[i]);
            else dp[i+1][j] = dp[i][j];
        }
    }
    cout << dp[n][W] << endl;
    return 0;
}