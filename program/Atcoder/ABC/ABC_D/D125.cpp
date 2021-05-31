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
    vector<ll> a(n);
    int num = 0; 
    ll mi = 1001001001;
    ll tot = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < 0) {
            num++;
            tot += -a[i];
            mi = min(mi, -a[i]);
        }else{
            tot += a[i];
            mi = min(mi, a[i]);
        }
    }
    ll ans = 0;
    if(num%2){
        tot -= (2*mi);
        ans = tot;
    }else{
        ans = tot;
    }
    cout << ans << endl;
    return 0;
}