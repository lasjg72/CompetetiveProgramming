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

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        to[x].push_back(y);
    }
    int ans = 0;
    vector<int> dp(n, 0);
    for(int i = 0; i < n; i++){
        for(int tv : to[i]){
            dp[tv] = dp[i] + 1;
            ans = max(ans, dp[tv]);
        }
    }
    cout << ans << endl;
    return 0;
}