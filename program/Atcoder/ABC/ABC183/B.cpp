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
#include <iomanip>

using namespace std;
using ll = long long;

int main()
{
    double x, y, gx, gy;
    cin >> x >> y >> gx >> gy;
    gy *= -1;
    double a = (gy-y) / (gx-x);
    //cout << gx - x << endl;
    double b = y - a * x;
    // cout << a << endl;
    // cout << b << endl;
    double ans = -1 * b / a;
    cout << std::fixed << std::setprecision(10) << ans << endl;
    return 0;
}