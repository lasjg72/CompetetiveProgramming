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

ll mpow(int n, int x){
    if(x == 0) return 1;
    else if(x%2 == 0) return mpow(n, x/2)*mpow(n, x/2);
    else return mpow(n, x-1)*n;
}

int main()
{
    ll n;
    cin >> n;
    ll ans = 1e18;
    for(ll b = 60; b >= 0; b--){
        ll nb = pow(2, b);
        for(ll a = n/nb; a >= 0; a--){
            ll c;
            ll now = nb*a;
            if(now < 0) continue;
            if(now <= n){
                c = n-now;
                if(ans > a+b+c) ans = a+b+c;
                else break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
