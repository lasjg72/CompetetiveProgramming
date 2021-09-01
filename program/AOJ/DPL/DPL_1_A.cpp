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
int dp[50005];
const int INF = 1001001001;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    for(int i = 0; i < m; i++){
        cin >> c[i];
    }
    for(int i = 0; i <= n; i++){
        dp[i] = INF;
    }
    dp[n] = 0;
    for(int i = n; i >= 0; i--){
        for(int j = 0; j < m; j++){
            if(i-c[j] >= 0)
            dp[i-c[j]] = min(dp[i-c[j]], dp[i]+1);
        }
    }
    cout << dp[0] << endl;
    return 0;
}