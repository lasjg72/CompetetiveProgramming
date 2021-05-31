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
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i< n; i++){
        cin >> a[i];
    }
    ll ans = 0;
    bool fi = true;
    for(int bit = 0; bit < (1<<(n-1)); bit++){
        ll tmp1 = 0, tmp2 = 0;
        bool ok = true;
        for(int i = 0; i < n-1; i++){
            tmp1 = tmp1 | a[i];
            if(bit & (1<<i)){
                ok = false;
                tmp2 ^= tmp1;
                tmp1 = 0;
            }
        }
        tmp1 = tmp1 | a[n-1];
        tmp2 ^= tmp1;
        // if(ok){
        //     if(fi) {
        //         ans = tmp1;
        //         fi = false;
        //     }else{
        //       ans = min(ans, tmp1);   
        //     }    
        // }
        if(ok) continue;
        if(fi) {
            ans = tmp2;
            fi = false;
        }
        else ans = min(ans, tmp2);
    }
    if(n == 1) ans = a[0];
    cout << ans << endl;
    return 0;
}