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
    ll a, b, n;
    cin >> a >> b >> n;
    int ans;
    if(b == 1) ans = 0;
    else{
        ll c = min(b-1, n);
        ans = floor(a*c/b);
    }
    cout << ans << endl;
    return 0;
}