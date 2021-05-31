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
using P = pair<ll, int>;

const int INF = 1001001001;

int main()
{
    int n;
    cin >> n;
    vector<P> x(n), y(n), tx(n), ty(n);
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        x[i] = {a-b, i};
        y[i] = {a+b, i};
        tx[i] = {a-b, i};
        ty[i] = {a+b, i};
    }
    sort(tx.begin(), tx.end());
    sort(ty.begin(), ty.end());
    
    ll xmx = tx[n-1].first, ymx = ty[n-1].first;
    ll xmi = tx[0].first, ymi = ty[0].first;

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, abs(xmx-x[i].first));
        ans = max(ans, abs(xmi-x[i].first));
        ans = max(ans, abs(ymx-y[i].first));
        ans = max(ans, abs(ymi-y[i].first));
    }
    cout << ans << endl;
    return 0;
}