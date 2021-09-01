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
const int mod = 10007;
int dp[1000005];

int main()
{
    int n;
    cin >> n;
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3; i < n; i++){
        dp[i] = dp[i-1]+dp[i-2];
        dp[i] %= mod;
        dp[i] += dp[i-3];
        dp[i] %= mod;
    }
    cout << dp[n-1] << endl;
    return 0;
}