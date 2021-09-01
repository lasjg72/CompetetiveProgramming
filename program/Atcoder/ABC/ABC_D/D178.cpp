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

ll dp[2005];

int main()
{
    int s;
    cin >> s;
    dp[0] = 1;
    for(int i = 1; i <= s; i++){
        for(int j = 0; j <= i-3; j++){
            dp[i] += dp[j];
            dp[i] %= mod;
        }
    }
    cout << dp[s] << endl;
    return 0;
}