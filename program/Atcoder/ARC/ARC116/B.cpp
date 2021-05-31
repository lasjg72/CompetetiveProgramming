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
const int mod = 998244353;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll tot = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        tot += a[i];
    }
    
    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++){
        tot = (tot * 2)%mod;
    }
    cout << tot << endl;
    return 0;
}