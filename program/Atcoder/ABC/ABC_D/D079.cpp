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
const int INF = 1001001001;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> dp(10, vector<int>(10, INF));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> dp[i][j];
        }
    }
    vector<vector<int>> a(h, vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }
    for(int k = 0; k < 10; k++){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(a[i][j] == -1) continue;
            ans += dp[a[i][j]][1];
        }
    }
    cout << ans << endl;
    return 0;
}