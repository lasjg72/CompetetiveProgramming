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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = -1001001001;
    ans = max(ans, a-c);
    ans = max(ans, b-c);
    ans = max(ans, a-d);
    ans = max(ans, b-d);
    cout << ans << endl;
    return 0;
}