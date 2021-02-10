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
    ll n, w;
    cin >> n >> w;
    vector<ll> a(200000, 0);
    ll mx = 0;
    for(int i = 0; i < n; i++){
        ll s, t, p;
        cin >> s >> t >> p;
        a[s] += p;
        a[t] -= p;
        mx = max(mx, t);
    }
    ll tmp = 0;
    //cout << mx << endl;
    for(int i = 0; i < mx; i++){
        //cout << a[i] << endl;
        tmp += a[i];
        //cout << "tmp: " << tmp << endl;
        if(tmp > w){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}