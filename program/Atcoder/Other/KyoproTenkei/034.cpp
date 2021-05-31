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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll l = 0, r = 0;
    set<ll> st;
    multiset<ll> mst;
    map<ll, ll> mp;
    ll ans = 1;
    // while(r < n-1){
    //     r++;
    //     st.insert(a[r]);
    //     mst.insert(a[r]);
    //     mp[a[r]]++;
    //     while((ll)st.size() > k){
    //         mp[a[l]]--;
    //         mst.erase(a[l]);
    //         if(mp[a[l]] == 0) {
    //             st.erase(a[l]);
    //         }
    //         l++;
    //     }
    //     ans = max(ans, (ll)mst.size());
    // }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        //cout << "i: " << i << endl;
        while(r < n){
            if(mp[a[r]] == 0 && st.size() == k) break;
            mst.insert(a[r]);
            st.insert(a[r]);
            mp[a[r]]++;
            r++;
        }
        //cout << "r: " << r << endl;
        ans = max(ans, r-i);
        if(mp[a[i]] == 1) st.erase(a[i]);
        auto it = mst.find(a[i]);
        if(it != mst.end()) mst.erase(it);
        mp[a[i]]--;
    }
    cout << ans << endl;
    return 0;
}