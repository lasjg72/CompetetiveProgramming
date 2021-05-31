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

int m;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    if(a/gcd(a, b) > m/b) return -1;
    else return a/gcd(a, b)*b;
}

int main()
{
    int n;
    cin >> n >> m;
    vector<ll> a(n);
    ll num = 0;
    set<ll> s;
    cin >> a[0];
    ll now = a[0];
    while(now%2 == 0){
        now /= 2;
        num++;
    }
    for(int i = 1; i < n; i++) {
        cin >> a[i];
        ll tmp = a[i];
        ll nt = 0;
        while(tmp%2 == 0){
            tmp /= 2;
            nt++;
        }
        if(nt != num){
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i = 0; i < n; i++) a[i] /= 2;
    ll res = 1;
    for(int i = 0; i < n; i++){
        res = lcm(res, a[i]);
        if(res == -1){
            cout << 0 << endl;
            return 0;
        }
    }
    if((m/res)%2 == 0) cout << (m/res)/2 << endl;
    else cout << (m/res)/2+1 << endl;
    return 0;
}