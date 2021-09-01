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
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll nx, ny;
    if(n%2){
        nx = x[(n-1)/2];
        ny = y[(n-1)/2];
    }else{
        nx = x[n/2];
        ny = y[n/2];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += (ll)abs((nx-x[i]));
        ans += (ll)abs((ny-y[i]));
    }
    if(n%2 == 0){
        nx = x[n/2-1];
        ny = y[n/2-1];
        ll tmp = 0;
        for(int i = 0; i < n; i++){
            tmp += (ll)abs((nx-x[i]));
            tmp += (ll)abs((ny-y[i]));
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}