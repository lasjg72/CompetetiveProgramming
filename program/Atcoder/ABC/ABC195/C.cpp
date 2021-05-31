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

int main()
{
    ll n;
    cin >> n;
    ll tmp = n;
    ll num = 1;
    while(tmp >= 10){
        tmp /= 10;
        num++;
    }
    vector<ll> dp(num, 0);
    for(ll i = 3; i < num; i++){
        if(i%3 == 1){
            dp[i] = ((pow(10, i+3-1)-1)-pow(10, i-1)+1) * (i/3);
        }
    }
    if(num <= 3){
        cout << 0 << endl;
        return 0;
    }
    ll now = 1;
    ll a = num;
    if(a % 3 != 1){
        a--;
    }
    if(a % 3 != 1){
        a--;
    }
    while(a > 1){
        now *= 10;
        a--;
    }
    //cout << "now: " << now << endl;
    ll ans = 0;
    //cout << "kore: " << (n-now+1)*(num/3) << endl; 
    if(num % 3 == 0){
        ans += (n-now+1)*(num/3-1);
    }else{
        ans += (n-now+1)*(num/3);
    }
    now /= 1000;
    for(ll i = 3; i <= num-3; i++){
        ans += dp[i];
        // if(dp[i] > 0){
        //     cout << "dp: " << dp[i] << "i: " << i << endl;
        // }
    }
    cout << ans << endl;
    return 0;
}