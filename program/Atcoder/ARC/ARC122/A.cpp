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
const int mod = 1e9+7;
ll num[100005][2];

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    num[1][0] = 1;
    num[1][1] = 1;
    num[0][0] = 1;

    for(int i = 2; i < n; i++){
        num[i][0] = num[i-1][0] + num[i-1][1];
        num[i][0] %= mod;

        num[i][1] = num[i-1][0];
    }
    
    ll ans = a[0]*((num[n-1][0]+num[n-1][1])%mod)%mod;
    if(n-1 != 0){
        ans += (a[n-1]*num[n-1][0])%mod;
        ans %= mod;
        ans -= (a[n-1]*num[n-1][1])%mod;
        ans += mod;
        ans %= mod;
    }

    for(int i = 1; i < n-1; i++){
        ll num1 = num[i-1][0]+num[i-1][1];
        ll num2 = num[n-i-1][0]+num[n-i-1][1];
        num1 %= mod;
        num2 %= mod;
        //cout << "num1: " << num1 << " " << num2 << endl;
        ans += (((a[i]*num1)%mod)*num2)%mod;
        num1 = num[i-1][0];
        num2 = num[n-i-1][0];
        ans = ans-(((a[i]*num1)%mod)*num2)%mod;
        ans += mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}