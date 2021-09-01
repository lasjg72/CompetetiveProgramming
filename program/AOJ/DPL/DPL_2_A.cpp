#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <cstring>

using namespace std;
using ll = long long;

struct edge{
    int to;
    int cost;
    edge(int to, int cost):to(to), cost(cost){};
};
int n;
const int INF = 1001001001;

int dp[1<<15][15];
int d[15][15];

int main()
{
    int m;
    cin >> n >> m;
    vector<vector<edge>> g(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            d[i][j] = INF;
        }
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c;
    }
    int ans = INF;
    for(int sv = 0; sv < 1; sv++){
        
        for(int i = 0; i < (1<<n); i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = INF;
            }
        }
        dp[0][sv] = 0;
        for(int S = 0; S < (1<<n); S++){
            for(int v = 0; v < n; v++){
                for(int u = 0; u < n; u++){
                    if(S != 0 && !(S&(1<<u))) continue;
                    if(d[u][v] == -1) continue;
                    if(!(S&(1<<v))) dp[S|(1<<v)][v] = min(dp[S|(1<<v)][v], dp[S][u]+d[u][v]);
                }
            }
        }
        
        ans = min(ans, dp[(1<<n)-1][sv]);
    }
    if(ans != INF){
    cout << ans << endl;
    }else cout << -1 << endl;
    return 0;
}