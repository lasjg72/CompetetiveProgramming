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
    ll n = 998244353;
    ll s = 897581057;
    ll k = 595591169;
    cout << (n-s)%k << endl;
    cout << n % k << endl;
    ll now = n-s;
    ll tmp = n % k;
    while(now % k != 0){
        now %= k;
        now += tmp;
    }
    return 0;
}