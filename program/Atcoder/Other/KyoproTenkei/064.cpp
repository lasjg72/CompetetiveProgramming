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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), sa(n-1, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll tot = 0;
    for(int i = 0; i < n-1; i++) tot += abs(a[i+1]-a[i]);
    for(int i = 0; i < n-1; i++) sa[i] = a[i+1]-a[i];
    //cout << "tot: " << tot << endl;
    while(q--){
        int l, r;
        ll v;
        cin >> l >> r >> v;
        l--; r--;
        
        if(l != 0) {
            tot -= abs(sa[l-1]);
            sa[l-1] += v;
            tot += abs(sa[l-1]);
        }
        if(r != n-1) {
            tot -= abs(sa[r]);
            sa[r] -= v;
            tot += abs(sa[r]);
        }
        cout << tot << endl;
    }
    return 0;
}