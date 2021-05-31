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
ll dp[100005];

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = 0;
    dp[0] = a[0]/2;
    a[0] %= 2;
    for(int i = 1; i < n; i++){
        if(a[i] == 0){
            dp[i] = dp[i-1];
            continue;
        }
        if(a[i-1] > 0 && a[i] > 0){
            a[i-1]--;
            a[i]--;
            dp[i] = dp[i-1] + 1 + a[i]/2;
        }else{
            dp[i] = dp[i-1] + a[i]/2;
        }
        a[i] %= 2;
    }
    cout << dp[n-1] << endl;
    return 0;
}