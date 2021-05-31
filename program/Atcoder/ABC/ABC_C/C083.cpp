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
    ll x, y;
    cin >> x >> y;
    ll ans = 0;
    while(y >= x){
        ans++;
        x *= 2;
    }
    cout << ans << endl;
    return 0;
}