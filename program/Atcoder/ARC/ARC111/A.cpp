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
    ll n, m;
    cin >> n >> m;
    ll tmp = m;
    ll mketa = 1;
    while(tmp % 10 != 0){
        tmp %= 10;
        mketa++;
    }
    map<ll, ll> amari;
    ll nketa = n+1;
    ll ans = 0;
    ll tmp = pow(10, mketa) / m;
    ll a = tmp % m;
    amari[a]++;
    

    return 0;
}
