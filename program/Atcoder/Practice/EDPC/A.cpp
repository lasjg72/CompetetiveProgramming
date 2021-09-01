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
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) dp[i] = INF;
    dp[0] = 0;
    
    for(int i = 0; i < n-1; i++){
        if(i+1 < n) dp[i+1] = min(dp[i+1], dp[i]+abs(h[i]-h[i+1]));
        if(i+2 < n) dp[i+2] = min(dp[i+2], dp[i]+abs(h[i]-h[i+2]));
    }
    cout << dp[n-1] << endl;
    return 0;
}