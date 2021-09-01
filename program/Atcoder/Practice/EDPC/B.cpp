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

int dp[100005];
const int INF = 1001001001;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) dp[i] = INF;
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(i+j < n) dp[i+j] = min(dp[i+j], dp[i]+abs(h[i]-h[i+j]));
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}