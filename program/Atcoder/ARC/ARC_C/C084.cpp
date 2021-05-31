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
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    vector<ll> numa(n, 0), numb(n, 0);
    for(int i = 0; i < n; i++){
        int now = a[i];
        auto itrb = upper_bound(b.begin(), b.end(), now);
        numa[i] = itrb-b.begin();
    }
    for(int i = 0; i < n; i++){
        int now = b[i];
        auto itrc = upper_bound(c.begin(), c.end(), now);
        numb[i] = n-(itrc-c.begin());
    }
    vector<ll> sumb(n+1, 0);
    for(int i = n-1; i >= 0; i--){
        sumb[i] = sumb[i+1] + numb[i];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += sumb[numa[i]];
    }
    cout << ans << endl;
    return 0;
}