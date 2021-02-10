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
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        ll tmp = (b - a + 1) * (a + b) / 2;
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}