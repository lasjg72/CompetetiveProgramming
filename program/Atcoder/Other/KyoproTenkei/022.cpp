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

ll mcd(ll x, ll y){
    if(x%y ==0 ) return y;
    else return mcd(y, x%y);
}

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll mx = max(a, b);
    mx = max(mx, c);
    ll tar = mcd(a, b);
    tar = mcd(tar, c);
    cout << a/tar-1+b/tar-1+c/tar-1 << endl;
    return 0;
}