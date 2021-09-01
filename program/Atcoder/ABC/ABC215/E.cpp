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
ll dp[1005][1<<10][10];
const int mod = 998244353;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 1; i <= n; i++){
        int now = s[i-1]-'A';
        for(int j = 0; j < (1<<10); j++){
            for(int k = 0; k < 10; k++){
                // I dont use the ith character
                if(j&(1<<k)){
                    dp[i][j][k] += dp[i-1][j][k];
                    dp[i][j][k] %= mod;

                    if(now == k){
                        dp[i][j][k] += dp[i-1][j][k];
                        dp[i][j][k] %= mod;
                    }else if(~(j>>now)&1){ // if I dont use 'now' character in j case
                        dp[i][j|(1<<now)][now] += dp[i-1][j][k];
                        dp[i][j|(1<<now)][now] %= mod;
                    }
                }
                
            }
        }
        dp[i][1<<now][now]++;
        dp[i][1<<now][now] %= mod;
    }
    ll ans = 0;
    for(int i = 0; i < 1<<10; i++){
        for(int j = 0; j < 10; j++){
            if(i&(1<<j)){
                ans += dp[n][i][j];
                ans %= mod;
            }
        }
    }
    cout << ans << endl;
    return 0;
}