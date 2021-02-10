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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < 100005; i++) dp[i] = 1001001001;

    dp[0] = 0;
    
    for(int i = 1; i < n; i++){
        chmin(dp[i], dp[i-1] + abs(a[i]- a[i-1]));
        if(i > 1) chmin(dp[i], dp[i-2] + abs(a[i]- a[i-2]));
        //cout << dp[i] << endl;
    }
    cout << dp[n-1] << endl;
    return 0;
}