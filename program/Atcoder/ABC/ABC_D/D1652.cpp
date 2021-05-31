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
    ll a, b, n;
    cin >> a >> b >> n;
    ll ans = 0;
    for(int i = 0; i <= 1000000; i++){
        ll x = n-i;
        if(x <= 0) break;
        ans = max((double)ans, floor(a*x/b)-a*floor(x/b));
    }
    cout << ans << endl;
    return 0;
}