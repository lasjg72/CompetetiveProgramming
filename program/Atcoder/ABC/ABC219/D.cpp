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

int dp[305][305][305];
const int INF = 1001001001;

int main()
{
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    vector<pair<int, int>> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= 300; j++){
            for(int k = 0; k <= 300; k++){
                dp[i][j][k] = INF;
            }
        }
    }
    for(int i = 0; i < n; i++){
        dp[i][0][0] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            for(int k = 0; k <= y; k++){
                if(j+p[i-1].first > x && k+p[i-1].second > y){
                    dp[i][x][y] = min(dp[i-1][j][k]+1, dp[i][x][y]);
                    dp[i][x][y] = min(dp[i][x][y], dp[i-1][x][y]);
                }else if(j+p[i-1].first > x){
                    dp[i][x][k+p[i-1].second] = min(dp[i-1][j][k]+1, dp[i][x][k+p[i-1].second]);
                    dp[i][x][k+p[i-1].second] = min(dp[i-1][x][k+p[i-1].second], dp[i][x][k+p[i-1].second]);
                }else if(k+p[i-1].second > y){
                    dp[i][j+p[i-1].first][y] = min(dp[i-1][j][k]+1, dp[i][j+p[i-1].first][y]);
                    dp[i][j+p[i-1].first][y] = min(dp[i][j+p[i-1].first][y], dp[i-1][j+p[i-1].first][y]);
                }
                else{
                    dp[i][j+p[i-1].first][k+p[i-1].second] = min(dp[i-1][j][k]+1, dp[i-1][j+p[i-1].first][k+p[i-1].second]);
                }
                dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]);
                
            }
        }
    }
    int ans = INF;
    ans = min(ans, dp[n][x][y]);
    if(ans == INF){
        cout << -1 << endl;
    }else cout << ans << endl;
    return 0;
}