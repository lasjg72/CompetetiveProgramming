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
    int n, q;
    cin >> n >> q;
    vector<ll> x(n), y(n), tx(n), ty(n);
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        x[i] = a-b;
        y[i] = a+b;
        tx[i] = a-b;
        ty[i] = a+b;
    }
    sort(tx.begin(), tx.end());
    sort(ty.begin(), ty.end());
    
    ll xmx = tx[n-1], ymx = ty[n-1];
    ll xmi = tx[0], ymi = ty[0];

    
    while(q--){
        ll ans = 0;
        int nq;
        cin >> nq;
        nq--;
        ans = max(ans, abs(xmx-x[nq]));
        ans = max(ans, abs(xmi-x[nq]));
        ans = max(ans, abs(ymx-y[nq]));
        ans = max(ans, abs(ymi-y[nq]));
        cout << ans << endl;
    }
    return 0;
}