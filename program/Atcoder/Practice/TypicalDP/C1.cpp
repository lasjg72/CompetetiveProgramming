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

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int dp[100005][3];

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k<3; k++){
                if(j != k) dp[i][k] = max(dp[i][k], dp[i-1][j]+a[i][k]);
            }
        }
    }
    int ans = -1;
    for(int i = 0; i < 3; i++){
        chmax(ans, dp[n-1][i]);
    }
    cout << ans << endl;
    return 0;
}