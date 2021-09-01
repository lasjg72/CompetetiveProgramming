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
using P = pair<int, int>;

int calc(ll x, ll y){
    int num = 0;
    for(ll i = 1; i*i <= x; i++){
        if(i < y) continue;
        if(x%i == 0){
            num++;
            //cout << y << " " << i << " " << x << endl;
        }
    }
    return num;
}

int main()
{
    ll k;
    cin >> k;
    int ans = 0;
    for(ll i = 1; i*i <= k; i++){
        if(k%i != 0) continue;
        ll j = k/i;
        ans += calc(j, i);
    }
    cout << ans << endl;
    return 0;
}