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
    ll x, y, a, b;
    cin >> x >> y >> a >> b;

    ll ans = 0;
    while(y > x*a && x * a - x < b){
        x *= a;
        ans++;
    }

    ans += (y-1-x)/b;

    cout << ans << endl;
    return 0;
}