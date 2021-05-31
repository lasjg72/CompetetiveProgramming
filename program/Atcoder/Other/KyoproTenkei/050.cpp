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

const int mod = 1e9+7;
int dp[100005];

int main()
{
    int n, l;
    cin >> n >> l;
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        if(i+1 <= n) dp[i+1] = (dp[i+1]+dp[i])%mod;
        if(i+l <= n) dp[i+l] += (dp[i+l]+dp[i])%mod;
    }
    cout << dp[n] << endl;
    return 0;
}