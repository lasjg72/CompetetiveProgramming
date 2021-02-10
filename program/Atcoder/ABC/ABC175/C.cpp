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
    ll x, k, d;
    cin >> x >> k >> d;
    if(x < 0) x *= -1;
    ll num = x / d; //何回左に移動できるか
    ll ans1 = x - num * d; //解候補
    if(num >= k){ //0近くをうろうろしない場合
        cout << x - (d * k) << endl;
        return 0;
    }
    ll ans2 = abs(x - num * d - d); //解候補
    if(k % 2 == num % 2) cout << ans1 << endl;
    else cout << ans2 << endl;
    return 0;
}