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
int dp[10005];

int main()
{
    int n, W;
    cin >> n >> W;
    vector<int> v(n), w(n);
    for(int i = 0; i < n; i++){
        cin >> v[i] >> w[i];
    }
    for(int i = 0; i <= W; i++){
        for(int j = 0; j < n; j++){
            if(i-w[j] >= 0) dp[i] = max(dp[i], dp[i-w[j]]+v[j]);
        }
    }
    cout << dp[W] << endl;
    return 0;
}