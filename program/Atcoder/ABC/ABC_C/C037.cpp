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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), sum(n+1, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum[i+1] = sum[i]+a[i];
    }
    ll ans = 0;
    for(int i = 0; i+k <= n; i++){
        ans += sum[i+k] - sum[i];
        //cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}