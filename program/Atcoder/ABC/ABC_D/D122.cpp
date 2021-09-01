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

ll dp[101][4][4][4];

int main()
{
  int n;
  cin >> n;
  dp[0][3][3][3] = 1;
  for(int len = 0; len < n; len++){
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++){
        for(int k = 0; k < 4; k++){
          if(dp[len][i][j][k] == 0) continue;
            
          for(int c = 0; c < 4; c++){
            if(c == 2){
              if(i == 1 && j == 0) continue;
              if(i == 0 && j == 1) continue;
              if(i == 1 && k == 0) continue;
              if(j == 1 && k == 0) continue;
            }
            if(c == 1 && i == 2 && j == 0) continue;
            dp[len+1][c][i][j] += dp[len][i][j][k];
            dp[len+1][c][i][j] %= mod;
          }
        }
      }
    }
  }
  ll ans = 0;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 4; k++){
        ans += dp[n][i][j][k];
        ans %= mod;
      }
    }
  }
  cout << ans << endl;
  return 0;
}