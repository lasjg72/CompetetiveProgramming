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
ll dp[105][100005];

int main()
{
    int n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);
    for(int i = 0; i< n; i++){
        cin >> w[i] >> v[i];
    }
    dp[0][0] = 0;
    for(int i = 0; i< n; i++){
        for(int sum_v = 0; sum_v <= 100100; sum_v++){
            if(sum_v-w[i] >= 0){
                dp[i+1][sum_v] = max(dp[i][sum_v], dp[i][sum_v-w[i]]+v[i]);
            }
            dp[i+1][sum_v] = max(dp[i+1][sum_v], dp[i][sum_v]);
        }
    }
    cout << dp[n][W] << endl;
    return 0;
}