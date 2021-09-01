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
const int mod = 998244353;

int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 1; i*i <= n; i++){
        ll r = n/i;
        if((r-i+1)%2==0){
            ans += (r-i+1)/2;
            ans %= mod;
        }else{
            if(i%2 == r%2){
                ans += (r-i+1)/2;
                ans %= mod;
                ans += 1;
                ans %= mod;
            }else{
                ans += (r-i+1)/2;
                ans %= mod;
            }
        }
    }
    cout << ans << endl;
    return 0;
}