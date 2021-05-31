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
    ll ans = 0;
    for(ll i = 1; i*i <= n; i++){
        if(n % i == 0){
            ll d1 = i-1;
            ll d2 = n/i-1;
            if(d1 != 0 && n/d1 == n % d1) ans += d1;
            if(d2 != 0 && n/d2 == n % d2) ans += d2;
        }
    }
    cout << ans << endl;
    return 0;
}