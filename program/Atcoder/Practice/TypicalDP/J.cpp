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

double dp[910][305][305];

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int tot = 0, num = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        tot += a[i];
        if(a[i] == 1) num++;
    }
    dp[0][n][num] = 1;
    for(int i = 1; i < tot+1; i++){
        for(int j = n-1; j >= 0; j--){
            for(int k = 0; k < j+1; k++){
                dp[i][j][k] += dp[i-1][j+1][k+1] * (k+1) / (j+1) + dp[i-1][j+1][k] * (j+1-k) / (j+1);
            }
        }
    }
    cout << dp[1][2][2] << endl;
    printf("%.10f\n", dp[tot][0][0]);
    return 0;
}