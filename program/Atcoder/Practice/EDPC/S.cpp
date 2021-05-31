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

ll dp[10005][101][2];

int main()
{
    string k;
    cin >> k;
    int n = k.size();
    int d;
    cin >> d;
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++){
        int now = k[i]-'0';
        for(int j = 0; j < 10; j++){
            if(now == j){
                for(int p = 0; p < d; p++){
                    dp[i+1][(p+j)%d][0] += dp[i][p][0];
                    dp[i+1][(p+j)%d][0] %= mod;
                    dp[i+1][(p+j)%d][1] += dp[i][p][1];
                    dp[i+1][(p+j)%d][1] %= mod;
                } 
            }else if(now > j){
                for(int p = 0; p < d; p++){
                    dp[i+1][(p+j)%d][1] += (dp[i][p][1]+dp[i][p][0])%mod;
                    dp[i+1][(p+j)%d][1] %= mod;
                }
            }else if(now < j){
                for(int p = 0; p < d; p++){
                    dp[i+1][(p+j)%d][1] += dp[i][p][1];
                    dp[i+1][(p+j)%d][1] %= mod;
                }
            }
        }
    }
    cout << (dp[n][0][0]+dp[n][0][1]-1+mod)%mod << endl;
    return 0;
}