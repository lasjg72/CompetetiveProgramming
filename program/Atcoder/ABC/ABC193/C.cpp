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
    ll n;
    cin >> n;
    ll ans = n;
    map<ll, ll> num; 
    for(ll i = 2; i*i <= n; i++){
        if(num[i] == 0){
            for(ll j = i*i; j <= n; j *= i){
                num[j]++;
                ans--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}