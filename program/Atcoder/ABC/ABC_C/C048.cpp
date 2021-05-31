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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > x){
            ans += a[i]-x;
            a[i] = x;
        }
    }
    for(int i = 0; i < n-1; i++){
        if(a[i]+a[i+1] <= x) continue;
        ans += a[i]+a[i+1]-x;
        a[i+1] -= a[i]+a[i+1]-x;
    }
    cout << ans << endl;
    return 0;
}