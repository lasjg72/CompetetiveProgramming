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
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
        c[i]--;
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int now = b[c[i]];
        ans += (ll)(upper_bound(a.begin(), a.end(), now)-lower_bound(a.begin(), a.end(), now));
    }
    cout << ans << endl;
    return 0;
}