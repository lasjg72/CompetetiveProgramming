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
    ll x, y;
    cin >> x >> y;
    ll ans = 1001001001;
    if(y > x){
        ans = min(ans, abs(y-x));
    }
    ans = min(ans, abs(x+y) + 1); // +1 means reverse
    ans = min(ans, abs(x-y) + 2);
    cout << ans << endl;
    return 0;
}