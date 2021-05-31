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
ll tree[1200001];

ll query(ll a, ll b, ll l, ll r, ll k){
    // cout << "---query start---" << endl;
    // cout << "a: " << a << " b: " << b << endl;
    // cout << "l: " << l << " r: " << r << endl;
    // cout << "k: " << k << endl;
    if(a <= l && b >= r) return tree[k];
    else if(r < a || l > b) return 0;
    else{
        int lv = query(a, b, l, (l+r)/2, 2*k+1);
        int rv = query(a, b, ceil(((double)l+(double)r)/2), r, 2*k+2);
        return lv^rv;
    }
}

void add(ll k, ll n, ll y){
    k += n-1;
    tree[k] ^= y;
    //cout << "k: " << k << "tree[k]: " << tree[k] << endl;
    while(k > 0){
        k = (k-1)/2;
        tree[k] ^= y;
        //cout << "k: " << k << "tree[k]: " << tree[k] << endl;
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int n_ = 1;
    while(n_ < n) n_*=2;
    for(int i = n_-1; i < n_-1+n; i++) {
        tree[i] = a[i-n_+1];
        // cout << "i: " << i << endl;
        // cout << tree[i] << endl;
    }
    for(int i = n_-2; i >= 0; i--){
        tree[i] = tree[2*i+1]^tree[2*i+2];
        // cout << "i: " << i << endl;
        // cout << tree[i] << endl;
    }
    // for(int i = 0; i < 7; i++){
    //     cout << tree[i] << endl;
    // }
    while(q--){
        ll t, x, y;
        cin >> t >> x >> y;
        x--; y--;
        if(t == 1){
            add(x, n_, y+1);
        }else if(t == 2){
            cout << query(x, y, 0, n_-1, 0) << endl;
        }
    }
    return 0;
}