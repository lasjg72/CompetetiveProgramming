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
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    for(int i = 0; i < 100005; i++) dp[i] = 1001001001;

    dp[0] = 0;

    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(i-j >= 0)
            chmin(dp[i], dp[i-j] + abs(h[i]-h[i-j]));
        }
    }
    cout << dp[n-1] << endl;
    return 0;
}