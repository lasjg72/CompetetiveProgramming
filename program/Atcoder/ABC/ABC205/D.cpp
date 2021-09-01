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
    vector<ll> a(n), num(n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        num[i] = a[i]-(i+1);
    }
    while(q--){
        ll k;
        cin >> k;
        if(a[n-1] < k){
            cout << k+n << endl;
            continue;
        }
        ll ans = 0;
        int pos = lower_bound(num.begin(), num.end(), k)-num.begin();
        if(pos == 0){
            cout << k << endl;
            continue;
        }
        cout << a[pos-1]+k-num[pos-1] << endl;
    }
    return 0;
}