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
    vector<ll> c(2*n+1);
    for(int i = 0; i < n; i++){
        double a, b;
        cin >> a >> b;
        c[2*i] = a-b;
        c[2*i+1] = b;
    }
    sort(c.rbegin(), c.rend());
    ll ans = 0;
    for(int i = 0; i < k; i++) ans += c[i];
    cout << ans << endl;
    return 0;
}