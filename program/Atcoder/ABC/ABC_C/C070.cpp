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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a/gcd(a, b)*b;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> t(n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
    } 
    if(n == 1){
        cout << t[0] << endl;
        return 0;
    }
    ll ans = lcm(t[0], t[1]);
    for(int i = 2; i < n; i++){
        ans = lcm(ans, t[i]);
    }
    cout << ans << endl;
    return 0;
}