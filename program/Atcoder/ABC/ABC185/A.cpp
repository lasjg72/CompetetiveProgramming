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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = min(a,b);
    ans = min(ans,c);
    ans = min(ans,d);
    cout << ans << endl;
    return 0;
}