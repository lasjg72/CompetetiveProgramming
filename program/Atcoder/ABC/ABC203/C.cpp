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
using P = pair<ll, ll>;

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<P> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    ll ans = 0, now = 0;
    for(int i = 0; i < n; i++){
        if(a[i].first-now > k){
            ans += k;
            cout << ans << endl;
            return 0;
        }else{
            k = k-(a[i].first-now)+a[i].second;
            ans += a[i].first-now;
            now = a[i].first;
        }
    }
    //cout << ans << endl;
    ans += k;
    cout << ans << endl;
    return 0;
}