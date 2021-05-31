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
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    vector<ll> f(2*n, 0);
    if(k < 0) k = -k;
    for(int i = 2; i <= 2*n; i++){
        f[i] = min(i-1, 2*n+1-i);
    }
    for(int i = k; i <= 2*n; i++){
        ans += f[i]*f[i-k];
    }
    cout << ans << endl;
    return 0;
}