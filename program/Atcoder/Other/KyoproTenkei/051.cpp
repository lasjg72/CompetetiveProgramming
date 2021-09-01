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
    ll p;
    cin >> n >> k >> p;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = n/2, r = n-l;
    
    vector<vector<ll>> tmp1(41), tmp2(41);
    for(int bit = 0; bit < (1<<l); bit++){
        ll t1 = 0;
        int num = 0;
        for(int i = 0; i < l; i++){
            if(bit>>i&1){
                t1 += a[i];
                num++;
            }
        }
        tmp1[num].push_back(t1);
    }
    for(int bit = 0; bit < (1<<r); bit++){
        ll t2 = 0;
        int num = 0;
        for(int i = 0; i < r; i++){
            if(bit>>i&1){
                t2 += a[i+l];
                num++;
            }
        }
        tmp2[num].push_back(t2);
    }
    ll ans = 0;
    for(int i = 0; i <= r; i++){
        sort(tmp2[i].begin(), tmp2[i].end());
    }
    for(int i = 0; i <= k; i++){
        if(k-i < 0) continue; 
        for(ll now : tmp1[i]){
            //cout << "now: " << now << endl;
            //cout << (upper_bound(tmp2[k-i].begin(), tmp2[k-i].end(), p-now)-tmp2[k-i].begin()) << endl;
            if(p-now < 0) continue;
            ans += (upper_bound(tmp2[k-i].begin(), tmp2[k-i].end(), p-now)-tmp2[k-i].begin());
        }
    }
    cout << ans << endl;
    return 0;
}