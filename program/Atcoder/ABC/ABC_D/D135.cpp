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
ll dp[100005][13];

int main()
{
    string s;
    cin >> s;
    dp[0][0] = 1;
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < 13; j++){
            if(s[i] == '?'){
                for(int k = 0; k < 10; k++){
                    dp[i+1][(10*j+k)%13] = (dp[i+1][(10*j+k)%13]+dp[i][j])%mod;
                }
            }else{
                int k = s[i]-'0';
                dp[i+1][(10*j+k)%13] = (dp[i+1][(10*j+k)%13]+dp[i][j])%mod;
            }
        }
    }
    cout << dp[s.size()][5] << endl;
    return 0;
}