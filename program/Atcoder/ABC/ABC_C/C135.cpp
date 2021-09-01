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
    int n;
    cin >> n;
    vector<ll> a(n+1), b(n);
    for(int i = 0; i < n+1; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] >= b[i]){
            ans += b[i];
        }else{
            ans += a[i];
            b[i] -= a[i];
            ans += min(a[i+1], b[i]);
            a[i+1] -= min(a[i+1], b[i]);
        }
    }
    cout << ans << endl;
    return 0;
}