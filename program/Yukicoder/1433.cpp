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
ll ans;
int n;
string s;

int main()
{
    cin >> n >> s;
    vector<ll> a(n), sum(n+1, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(s[i] == 'B') a[i] *= -1;
        sum[i+1] = a[i]+sum[i];
    }
    ll mx = -1001001001001001001, mi = 1001001001001001001;
    ll x = 0, y = 0;
    for(int i = 0; i < n; i++){
        x += a[i];
        y += a[i];
        // cout << "x: " << x << endl;
        // cout << "y: " << y << endl;
        
        mx = max(mx, x);
        mi = min(mi, y);
        if(x < 0) x = 0;
        if(y > 0) y = 0;
    }

    cout << max(mx, -mi) << endl;
    return 0;
}