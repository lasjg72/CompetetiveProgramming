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
    ll mod = 1e9+7;
    ll n;
    cin >> n;

    ll tot = 1;
    for(int i = 0; i < n; i++){
        tot = (tot * 10) % mod;
        tot = tot % mod;
    }
    //cout << "tot: " << tot << endl;
    
    ll no0 = 1;
    for(int i = 0; i < n; i++){
        no0 = (no0 * 9) % mod;
        no0 = no0 % mod;
    }
    
    //cout << "no0: " << no0 << endl;
    
    ll no09 = 1;
    for(int i = 0; i < n; i++){
        no09 = (no09 * 8) % mod;
        no09 = no09 % mod;
    }
    
    ll a = (no0 * 2) % mod;
    a = a % mod;
    ll b = (a - no09) % mod;
    b = b % mod;
    if(b < 0) b += 1e9+7;
    ll ans = (tot - b) % mod;
    ans = ans % mod;
    if(ans < 0) ans += 1e9+7;
    cout << ans << endl;
    return 0;
}