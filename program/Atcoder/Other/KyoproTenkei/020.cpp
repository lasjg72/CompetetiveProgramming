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

ll modpow(int x, int n){
    if(n == 0) return 1;
    else if(n%2 == 0) return modpow(x, n/2)*modpow(x, n/2);
    else return x*modpow(x, n-1);
}

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    if(modpow(c, b) > a) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}