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
    ll n,cost;
    cin >> n >> cost;
    //vector<ll> table(1000000000);
    vector<int> a(n), b(n), c(n);
    int mx = 0;
    int mi = 1e9;
    for(int i = 0; i < n; i++){
        //int a, b, c;
        //cin >> a >> b >> c;
        //a--;
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        mi = min(mi, a[i]);
        mx = max(mx, b[i]);
        // table[a] += c;
        // table[b] -= c;
    }
    const int size = 1001001001;
    vector<ll> table;
    table.resize(size);
    for(int i = 0; i < n; i++){
        table[a[i]] += c[i];
        table[b[i]] -= c[i];
    }
    for(ll i = mi; i < mx+1; i++){
        if(0 < i) table[i] += table[i-1];
        //cout << "table: " << table[i] << endl;
    }
    ll ans = 0;
    for(ll i = mi; i < mx+1; i++){
        ans += min(table[i], cost);
    }
    cout << ans << endl;
    return 0;
}