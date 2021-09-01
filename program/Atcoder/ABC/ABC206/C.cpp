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
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<int, ll> mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    set<int> st;
    ll ans = n*(n-1)/2;
    for(int i = 0; i < n; i++){
        if(st.find(a[i]) != st.end()) continue;
        ll num = mp[a[i]];
        ans -= num*(num-1)/2;
        st.insert(a[i]);
    }
    cout << ans << endl;
    return 0;
}