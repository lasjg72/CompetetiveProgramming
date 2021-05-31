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
const int mod = 1000000007;
ll dp[100005][8];

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = "atcoder";
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= 7; j++){
            if(j < 7 && s[i] == t[j]){
                dp[i+1][j+1] = (dp[i+1][j+1]+dp[i][j])%mod;
            }
            dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod;
        }
    }
    cout << dp[n][7] << endl;
    // for(int i = n-1; i >= 0; i--){
    //     if(s[i] == 'r'){
    //         mp[s[i]]++;
    //     }else if(s[i] == 'e' && mp['r'] != 0){
    //         cout << mp['r'] << endl;
    //         mp[s[i]]++;
    //         ans = ans*mp['r']%mod;
    //     }else if(s[i] == 'd' && mp['e'] != 0){
    //         mp[s[i]]++;
    //         ans = ans*mp['e']%mod;
    //     }else if(s[i] == 'o' && mp['d'] != 0){
    //         mp[s[i]]++;
    //         ans = ans*mp['d']%mod;
    //     }else if(s[i] == 'c' && mp['o'] != 0){
    //         mp[s[i]]++;
    //         ans = ans*mp['o']%mod;
    //     }else if(s[i] == 't' && mp['c'] != 0){
    //         mp[s[i]]++;
    //         ans = ans*mp['c']%mod;
    //     }else if(s[i] == 'a' && mp['t'] != 0){
    //         mp[s[i]]++;
    //         ans = ans*mp['t']%mod;
    //     }
    // }    
    //cout << ans << endl;
    return 0;
}