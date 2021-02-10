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
    ll mx = -1001001001001001000;
    mx = max(a * c, mx);
    mx = max(mx, a * d);
    mx = max(mx, b * c);
    mx = max(mx, b * d);
    //mx = max(mx, 0);
    cout << mx << endl;
    return 0;
}