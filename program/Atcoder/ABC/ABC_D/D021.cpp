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
const int MAX = 500000;

ll fac[MAX], finv[MAX], inv[MAX];

void init(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++){
        fac[i] = fac[i-1]*i%mod;
        inv[i] = mod-inv[mod%i]*(mod/i)%mod;
        finv[i] = finv[i-1]*inv[i]%mod;
    }
}

ll COM(int n, int k){
    if(n < k || n < 0 || k < 0) return 0;
    // cout << fac[n] << endl;
    // cout << finv[k] << endl;
    // cout << finv[n-k] << endl;
    return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}

int main()
{
    int n, k;
    cin >> n >> k;
    init();
    cout << COM(n-1+k, k) << endl;
    return 0;
}