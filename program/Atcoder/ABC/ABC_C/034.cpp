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

const int MAX = 500005;
const int MOD = 1000000007;

ll fac[MAX], finv[MAX], inv[MAX];

void init(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}

ll COM(int n, int x){
    if(n < x) return 0;
    if(n < 0 || x < 0) return 0;
    
    return fac[n]*(finv[x]*finv[n-x]%MOD) %MOD;
}

int main()
{
    int n, k;
    cin >> n >> k;
    n--; k--;
    init();
    cout << COM(n+k, k) << endl; 
    return 0;
}