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
    int n;
    cin >> n;
    vector<int> x(n), y(n), z(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> z[i];
    }
    vector<vector<int>> dp(1<<n, vector<int>(n, INF));
    dp[0][0] = 0;
    for(int S = 0; S < (1<<n); S++){
        for(int v = 0; v < n; v++){
            for(int u = 0; u < n; u++){
                if(S!= 0 && !(S&(1<<u))) continue;
                if(u != v && !(S&(1<<v))) dp[S|(1<<v)][v] = min(dp[S|(1<<v)][v], dp[S][u]+abs(x[u]-x[v])+abs(y[u]-y[v])+max(0, z[v]-z[u]));
            }
        }
    }
    cout << dp[(1<<n)-1][0] << endl;
    return 0;
}