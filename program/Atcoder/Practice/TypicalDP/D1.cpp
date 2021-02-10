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
        for(int sum_w = 0; sum_w <= W; sum_w++){
            if(sum_w-w[i] >= 0){
                dp[i+1][sum_w] = max(dp[i][sum_w], dp[i][sum_w-w[i]]+v[i]);
            }
            dp[i+1][sum_w] = max(dp[i+1][sum_w], dp[i][sum_w]);
        }
    }
    cout << dp[n][W] << endl;
    return 0;
}