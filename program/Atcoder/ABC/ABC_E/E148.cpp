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
    ll n;
    cin >> n;
    ll ans = 0;
    ll tmp = n;
    tmp /= 2;
    while(tmp){
        ans += tmp/5;
        tmp /= 5;
    }
    if(n % 2){
        cout << 0 << endl;
    }
    else cout << ans << endl;
    return 0;
}
