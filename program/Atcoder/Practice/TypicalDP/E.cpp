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
    vector<int> w(n), v(n);
    for(int i = 0; i< n; i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < 100001; j++){
            dp[i][j] = 1001001001;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i< n+1; i++){
        for(int j = 0; j < 100001; j++){
            if(j-v[i-1] >= 0) dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i-1]]+w[i-1]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    ll ans = 100000;
    while(dp[n][ans] > W) ans--;
    cout << ans << endl;
    return 0;
}