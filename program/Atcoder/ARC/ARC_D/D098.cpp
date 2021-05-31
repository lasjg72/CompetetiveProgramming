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
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = 0;
    ll xtot = a[0];
    ll tot = a[0];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += l-i;
        while(l < n && xtot == tot){
            ans++;
            l++;
            xtot ^= a[l];
            tot += a[l];
        }
        xtot ^= a[l];
        tot -= a[l];
        l--;
        xtot ^= a[i];
        tot -= a[i];
        // cout << "l: " << i << " r: " << l << endl;
        // cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}