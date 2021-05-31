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
    vector<int> a(n);
    ll tot = 0;
    for(int i = 0; i< n; i++){
        cin >> a[i];
        tot += a[i];
    }
    tot = tot * tot;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += (n-1)*pow(a[i], 2);
    }
    for(int i = 0; i < n; i++){
        tot -= pow(a[i], 2);
    }
    ans -= tot;
    cout << ans << endl;
    return 0;
}