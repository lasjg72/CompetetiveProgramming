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

const int mod = 1e9+7;

int main()
{
    int n, m;
    cin >> n >> m;
    ll ans = 1;
    int n2 = max(n, m);
    int m2 = min(n, m);
    for(int i = 0; i < n+m; i++){
        if(i%2 == 0){
            ans *= (ll)n2;
            ans %= mod;
            n2--;
        }else{
            ans *= (ll)m2;
            ans %= mod;
            m2--;
        }
    }
    if(n == m) cout << (ans*2)%mod << endl;
    else cout << ans << endl;
    return 0;
}