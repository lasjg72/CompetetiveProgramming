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
    if(k == 0){
        cout << n*n << endl;
    }else{
        ll ans = 0;
        for(ll i = 1; i <= n; i++){
            ll num = n/i;
            //cout << "i: " << i << endl;
            if(i-k >= 0) ans += num*(i-k);
            //cout << ans << endl;
            if(n%i-k+1 >= 0) ans += n%i-k+1;
            //cout << ans << endl;

        }
        cout << ans << endl;
    }
    return 0;
}