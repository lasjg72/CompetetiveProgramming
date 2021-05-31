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
    int h, n;
    cin >> h >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i <= h; i++){
        dp[i] = INF;
    }
    dp[h] = 0;
    for(int H = h; H >= 0; H--){
        for(int i = 0; i < n; i++){
            if(H-a[i] >= 0) dp[H-a[i]] = min(dp[H-a[i]], dp[H]+b[i]);
            else dp[0] = min(dp[0], dp[H]+b[i]);
        }
    }
    cout << dp[0] << endl;
    return 0;
}