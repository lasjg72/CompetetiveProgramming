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

const int MOD = 1e9+7;
const int MAX = 3000000;

ll fac[MAX], finv[MAX], inv[MAX];

void init(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i] = finv[i-1]*inv[i] %MOD;
    }
}

ll COM(int n, int x){
    if(n < x || n < 0 || x < 0) return 0;
    // cout << fac[n] << endl;
    // cout << finv[x] << endl;
    // cout << finv[n-x] << endl;
    
    return (fac[n]*((finv[x]*finv[n-x])%MOD))%MOD;
}

int main()
{
    int x, y;
    cin >> x >> y;
    int n = -1, k = -1;
    for(int i = 0; i <= x/2; i++){
        int nx = 2*i;
        int ny = i;
        if((x-nx)*2 == (y-ny)){
            n = i+(x-nx);
            k = i;
        }
    }
    //cout << "n: " << n << " k: " << k << endl;
    init();
    cout << COM(n, k) << endl;
    return 0;
}