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

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    vector<vector<int>> dp(h, vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }
    dp[0][0] = 1;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(i == 0 && j == 0) continue;
            else if(i == 0 && a[i][j] == '.'){
                dp[i][j] = dp[i][j-1];
            }
            else if(j == 0 && a[i][j] == '.'){
                dp[i][j] = dp[i-1][j];
            }
            else if(a[i][j] == '.'){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
            }
            else if(a[i][j] == '#'){
                dp[i][j] = 0;
            }
        }
    }
    cout << dp[h-1][w-1] << endl;
    return 0;
}