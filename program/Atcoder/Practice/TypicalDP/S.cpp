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

int dp[10005][105][2];

int main()
{
    string s;
    int D;
    cin >> s >> D;
    int len = s.size();
    dp[0][0][0] = 1;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < D; j++){
            for(int k = 0; k < 2; k++){
                int x = s[i] - '0';
                for(int d = 0; d < 10; d++){
                    int ni = i+1, nj = j, nk = k;
                    nj = (nj + d%D)%D;
                    if(k==0){
                        if(x < d) continue;
                        if(x > d) nk = 1;
                    }
                    dp[ni][nj][nk] = (dp[ni][nj][nk] + dp[i][j][k])%mod;
                    // cout << "-------------" << endl;
                    // cout << "d: " << d << endl;
                    // cout << "i: " << i << "j: " << j << "k: " << k << endl;
                    // cout << "dp: " << dp[ni][nj][nk] << endl;
                }
            }
        }
    }
    cout << (dp[len][0][0] + dp[len][0][1]-1+mod)%mod << endl;
    return 0;
}