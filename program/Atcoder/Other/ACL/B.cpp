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
    ll l = max(a, c);
    ll r = min(b, d);
    if(l <= r) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}