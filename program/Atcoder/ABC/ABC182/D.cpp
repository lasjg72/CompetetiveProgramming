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
    vector<ll> a(n), sum(n+1), sumsum(n+2), summax(n+1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum[i+1] = a[i] + sum[i];
        summax[i+1] = max(sum[i+1], summax[i]);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        sumsum[i+1] = sum[i] + sumsum[i];
        ll tmp = max(sumsum[i] + summax[i], sumsum[i+1]);
        // cout << "sum[" << i << "]: " << sum[i] << endl;
        // cout << "summax[" << i << "]: " << summax[i] << endl;
        // cout << "sumsum[" << i+1 << "]: " << sumsum[i+1] << endl;
        // cout << "-------" << endl;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}