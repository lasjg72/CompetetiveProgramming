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

const int mod = 998244353;
int dp[10][100005];

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    dp[a[0]][0] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < 10; j++){
            dp[(j+a[i])%10][i] += dp[j][i-1];
            dp[(j+a[i])%10][i] %= mod;
            
            dp[(j*a[i])%10][i] += dp[j][i-1];
            dp[(j*a[i])%10][i] %= mod;
        }
    }
    for(int i = 0; i < 10; i++){
        cout << dp[i][n-1] << endl;
    }
    return 0;
}