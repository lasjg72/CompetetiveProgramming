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
const int INF = 1001001001;

int main()
{
    ll n, W;
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
            if(j-v[i] < 0) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]] + w[i]);
        }
    }
    ll ans = 100000;
    while(dp[n][ans] > W) ans--;
    cout << ans << endl;
    return 0;
}