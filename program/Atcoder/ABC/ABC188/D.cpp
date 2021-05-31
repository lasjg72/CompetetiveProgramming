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
    ll n,cost;
    cin >> n >> cost;
    vector<ll> a(n), b(n), c(n);
    vector<P> p;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        p.push_back({a[i], c[i]});
        p.push_back({b[i], -c[i]});
    }
    sort(p.begin(), p.end());
    ll ans = 0, now = 0, pre = 0;
    for(int i = 0; i < 2*n; i++){
        ll pos = p[i].first;
        if(pre != pos){
            ans += min(now, cost)*(pos-pre);
            pre = pos;
        }
        now += p[i].second;
    }
    cout << ans << endl;
    return 0;
}