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
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> f(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> f[i];
    sort(a.begin(), a.end());
    sort(f.rbegin(), f.rend());
    ll l = -1, r = 1e18;
    while(r-l>1){
        ll tmp = k;
        ll mid = (r+l)/2;
        for(int i = 0; i < n; i++){
            if(a[i]*f[i] > mid){
                tmp -= a[i]-mid/f[i];
            }
        }
        if(tmp < 0){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << r << endl;
    return 0;
}