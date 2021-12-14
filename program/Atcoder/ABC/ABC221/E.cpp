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

ll modpow(ll a, ll b){
    if(b == 0) return 1;
    if(b%2 == 0) return (modpow(a, b/2)*modpow(a, b/2))%mod;
    else return modpow(a, b-1)*a%mod;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(a[i] <= a[j]){
                ans += modpow(2, j-i-1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}