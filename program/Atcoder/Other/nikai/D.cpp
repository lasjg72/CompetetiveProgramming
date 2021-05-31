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
const int mod = 1000000007;

long long pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}

int main()
{
    ll n, p;
    cin >> n >> p;
    ll ans = p-1;
    ll tmp = pow(p-2, n-1);
    //cout << "tmp: " << tmp << endl;
    ans = (ans*tmp) %mod;
    cout << ans << endl;
    return 0;
}