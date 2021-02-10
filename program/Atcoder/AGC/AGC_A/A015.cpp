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
    ll n, a, b;
    cin >> n >> a >> b;
    ll mx = a + b * (n-1);
    ll mi = a * (n-1) + b;
    ll ans = mx -mi+1;
    if(ans < 0){
        cout << 0 << endl;
    }else cout << ans << endl;
    return 0;
}