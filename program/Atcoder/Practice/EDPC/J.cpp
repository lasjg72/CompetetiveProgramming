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

// dp[c1][c2][c3]: 1個の寿司が残っている皿がc1枚、2個以下も同様の時の期待値
double dp[305][305][305];
int n;

double dfs(int i, int j, int k){

    if(dp[i][j][k] >= 0) return dp[i][j][k];
    if(i == 0 && j == 0 && k == 0) return 0.0;
    double res = 0;
    if(i > 0) res += dfs(i-1, j, k)*i;
    if(j > 0) res += dfs(i+1, j-1, k)*j;
    if(k > 0) res += dfs(i, j+1, k-1)*k;
    res += n;
    res *= 1.0/(i+j+k);

    return dp[i][j][k] = res;
}

int main()
{
    cin >> n;
    vector<int> a(n);
    int c1 = 0, c2 = 0, c3 = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1) c1++;
        else if(a[i] == 2) c2++;
        else if(a[i] == 3) c3++;
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= n; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    // double ans = dfs(c1, c2, c3);
    printf("%.10f\n", dfs(c1, c2, c3));
    return 0;
}