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


int dp[105][4][2];
int main()
{
    string s;
    int K;
    cin >> s >> K;
    int len = s.size();
    
    dp[0][0][0] = 1;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 2; k++){
                int x = s[i]-'0';
                for(int d = 0; d < 10; d++){
                    int ni = i+1, nj = j, nk = k;
                    if(d != 0) nj++;
                    if(nj > K) continue;
                    if(k==0){
                        if(d > x) continue;
                        if(d < x) nk = 1;
                    }
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }
    cout << dp[len][K][0] + dp[len][K][1] << endl;
    return 0;
}