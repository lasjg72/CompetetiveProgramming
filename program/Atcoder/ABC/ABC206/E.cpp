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
    ll l, r;
    cin >> l >> r;

    vector<ll> not_coprime(r+1);
    ll ans = 0;

    for(int i = r; i >= 2; i--){
        not_coprime[i] = (r/i-(l-1)/i)*(r/i-(l-1)/i);
        for(int j = 2*i; j <= r; j += i) not_coprime[i] -= not_coprime[j];
        ans += not_coprime[i];
    }

    for(int i = l; i <= r; i++){
        if(i == 1) continue;
        ans -= r/i*2-1;
    }

    cout << ans << endl;
    return 0;
}