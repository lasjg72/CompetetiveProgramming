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
    for(ll i = 1; i <= 10000; i++){
        for(ll j = i; j <= n/(i*j); j++){
            ll now = i*j;
            if(n/now >= j){
                ans += n/now-j+1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}