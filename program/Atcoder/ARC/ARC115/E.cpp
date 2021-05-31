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
    vector<ll> a(n), x(n), tmp(n);
    for(int i= 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n-1; i++){
        if(a[i] < a[i+1]){
            int num = a[i+1]-a[i];
            tmp[i] = a[i]-1+num;
        }else{
            int num = a[i]-a[i+1];
            tmp[i] = a[i+1]-1+num;
        }
    }
    ll ans = 1;
    for(int i = 0; i < n-1; i++){
        ans = (ans*tmp[i])%mod;
    }
    cout << ans << endl;
    return 0;
}