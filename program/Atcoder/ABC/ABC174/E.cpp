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
    ll total = 0;
    for(int i = 0; i< n; i++){
        cin >> a[i];
        total += a[i];
    }
    cout << "total: " << total << endl;
    ll tmp = total / (n+k);
    tmp += 1;
    cout << "tmp: " << tmp << endl;
    sort(a.begin(), a.end());
    if(k == 0){
        cout << a[n-1] << endl;
        return 0;
    }
    ll ans = 0;
    for(int i = 0; i< n; i++){
        if(a[i] < tmp) continue;
        ll num = a[i] / tmp;
        if(a[i] % tmp == 0) num--;
        if(a[i] % (num+1) == 0) ans = max(ans, a[i] / (num+1));
        else ans = max(ans, (a[i] / (num+1)) + 1);
    }
    cout << ans << endl;
    return 0;
}