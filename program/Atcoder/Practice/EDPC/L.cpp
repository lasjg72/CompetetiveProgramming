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

// dp[i][j]: 区間i, jが残っている状態でお互いが最善を尽くした時のX-Yの値
ll dp[3005][3005];

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int len = 1; len <= n; len++){
        for(int i = 0; i+len <= n; i++){
            int j = i+len;
            // タロウの番
            if((n-len)%2 == 0){
                dp[i][j] = max(dp[i+1][j]+a[i], dp[i][j-1]+a[j-1]);
            }else{
                dp[i][j] = min(dp[i+1][j]-a[i], dp[i][j-1]-a[j-1]);
            }
        }
    }
    cout << dp[0][n] << endl;
    return 0;
}