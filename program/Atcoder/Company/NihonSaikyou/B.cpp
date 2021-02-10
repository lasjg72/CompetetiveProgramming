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

const ll mod = 1e9+7;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll ans = 0;
    for(ll i =0 ; i< n; i++){
        cin >> a[i];
    }
    for(ll i =0 ; i <n; i++){
        ll l = 0, r = 0;
        for(ll j = 0; j < n; j++){
            if(i < j && a[i] > a[j]){
                r++;
                l++;
            }else if(i > j && a[i] > a[j]){
                l++;
            }
        }

        // for(int j = i; j < n; ++j) {
		// 	if( a[i] > a[j] ) r++;
		// }
		
		// for(int j = 0; j < n; ++j) {
		// 	if( a[i] > a[j] ) l++;
		// }

        //cout << "l: " << l << "r: " << r << endl;
        ll q=0;
        ans += (r*k)%mod;
        ans %= mod;
        q = (k*(k-1LL)/2LL)%mod;
        l %= mod;
        ans += (l*q) %mod;
        ans %= mod;

        // ans += (k * r) % mod;
		// ans %= mod;
		// ans += (l % mod) * ((k * (k - 1LL) / 2LL) % mod);
		// ans %= mod;
    }
    cout << ans << endl;
    return 0;
}