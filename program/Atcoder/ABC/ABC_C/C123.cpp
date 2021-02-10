#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main()
{
    ll a, b, c, d, e, n;
    cin >> n >> a >> b >> c >> d >> e;
    ll mi = min(a, min(b, min(c, min(d, e))));
    // ll ans = 4;
    // if(n % mi == 0) ans += n/mi;
    // else ans += n/mi + 1;
    ll ans = 5;
    ans += n/mi;
    cout << ans << endl;
    return 0;
}