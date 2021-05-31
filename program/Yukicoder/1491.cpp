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
    ll k;
    cin >> k;
    ll ans = (2*k+1)*(2*k+1);
    ans = ans - (3+(k-1)*4);
    cout << ans << endl;
    return 0;
}