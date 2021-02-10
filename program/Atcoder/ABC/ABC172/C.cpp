#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main()
{
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m), timea(n+1, 0), timeb(m+1, 0);
    for(ll i =0; i < n; i++){
        cin >> a[i];
        timea[i+1] = timea[i] + a[i];
    }
    for(ll i =0; i < m; i++){
        cin >> b[i];
        timeb[i+1] = timeb[i] + b[i];
    }
    ll ans = 0;
    for(ll i = 0; i< n+1; i++){
        ll tmp = 0;
        if(k < timea[i]) break;
        auto itr = upper_bound(timeb.begin(), timeb.end(), k-timea[i]);
        if(itr - timeb.begin() == timeb.end() - timeb.begin()) tmp = itr-timeb.begin()-1;
        else tmp = itr-timeb.begin()-1;
        tmp += i;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
