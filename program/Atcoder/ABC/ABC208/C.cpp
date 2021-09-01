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
using P = pair<int, int>;

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<P> b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = P(a[i], i);
    }
    sort(b.begin(), b.end());
    vector<ll> ans(n);
    for(int i = 0; i < n; i++) ans[i] = k/n;
    k %= n;
    for(int i = 0; i < n; i++){
        if(k <= 0) break;
        k--;
        ans[b[i].second]++;
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}