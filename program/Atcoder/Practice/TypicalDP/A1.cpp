#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

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

int dp[100005];

int main()
{
    int n;
    cin >> n;
    vector<int> h(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    dp[0]= 0;
    dp[1] = 0;
    dp[2] = abs(h[1]-h[2]);
    for(int i = 3; i <= n; i++){
        dp[i] = min(dp[i-1] + abs(h[i]-h[i-1]), dp[i-2] + abs(h[i]-h[i-2]));
    }
    cout << dp[n] << endl;
    return 0;
}