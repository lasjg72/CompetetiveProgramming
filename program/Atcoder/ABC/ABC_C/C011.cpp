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

int dp[305];
const int INF = 1001001001;

int main()
{
    int n;
    vector<int> ng(3);
    cin >> n >> ng[0] >> ng[1] >> ng[2];
    sort(ng.begin(), ng.end());
    for(int i = 0; i <= n; i++) dp[i] = INF;
    dp[n] = 0;
    for(int i = n; i >= 0; i--){
        if(ng[0] == i || ng[1] == i || ng[2] == i) continue;
        for(int j = 1; j <= 3; j++){
            dp[i-j] = min(dp[i] + 1, dp[i-j]);
        }
    }
    if(dp[0] == INF || dp[0] > 100){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
    return 0;
}