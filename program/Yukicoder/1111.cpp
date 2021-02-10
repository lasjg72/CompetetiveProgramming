#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int dp[301][301][301];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> p(m), q(m), c(m);
    for(int i = 0; i < m; i++){
        cin >> p[i] >> q[i] >> c[i];
    }
    dp[0][0][0]= 0;
    for(int i = 0; i < m; i++){
        dp[p[i]][q[i]][c[i]] = 1;
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < m; j++){
            for(int l = 0; l < m; l++){
                dp[p[j]][q[l]][i] = max(dp[])
            }
        }
    }
    return 0;
}