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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll tot = 0, ans = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        tot += a[i];
    }
    if(tot <= k){
        for(ll i = 0; i < n; i++){
            ans += (a[i]+1)*a[i]/2;
        }
        cout << ans << endl;
        return 0;
    }
    sort(a.rbegin(), a.rend());
    for(ll i = 0; i < n-1; i++){
        if((a[i]-a[i+1])*(i+1) <= k){
            k -= (a[i]-a[i+1])*(i+1);
            ans += (a[i]+1+a[i+1])*(a[i]-a[i+1])*(i+1)/2;
        }else{
            ll num = k/(i+1);
            k %= (i+1);
            ans += (a[i]-num+1+a[i])*num*(i+1)/2;
            ans += (a[i]-num)*k;
            k = 0;
        }
    }
    if(k > 0){
        ll num = k/n;
        k %= n;
        ans += (a[n-1]-num+1+a[n-1])*num*n/2;
        ans += (a[n-1]-num)*k;
    }
    cout << ans << endl;
    return 0;
}