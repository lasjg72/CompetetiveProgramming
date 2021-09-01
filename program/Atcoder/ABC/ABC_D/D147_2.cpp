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
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<ll>> num(60, vector<ll>(2, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 60; j++){
            if((a[i]>>j)&1){
                num[j][1]++;
            }else{
                num[j][0]++;
            }
        }
    }
    ll tmp = 1, ans = 0;
    for(int i = 0; i < 60; i++){
        ans += (((tmp*num[i][0])%mod)*num[i][1])%mod;
        tmp *= 2;
        tmp %= mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}