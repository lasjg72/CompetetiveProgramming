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
    if(2*n > m){
        cout << m/2 << endl;
    }else{
        ll ans = 0;
        ans += n;
        m = m - 2*n;
        ans += m/4;
        cout << ans << endl;
    }
    return 0;
}