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
ll dp[3005];

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n), sum(n+1, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum[i+1] = sum[i] + a[i];
    }
    dp[1] = 1;
    dp[0] = 0;
    for(int i = 2; i <= n; i++){
        for(int j = 1 ; j < i; j++){
            if((sum[i]-sum[j])%(i-j) == 0){
                dp[i] += dp[j];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}