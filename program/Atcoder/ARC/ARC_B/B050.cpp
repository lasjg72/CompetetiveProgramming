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
    ll R, B;
    cin >> R >> B;
    ll x, y;
    cin >> x >> y;
    ll l = 0, r = 1e18+1;
    while(r-l>1){
        // mid本花束を作れるか
        ll mid = (l+r)/2;
        if(R-mid < 0 || B-mid < 0){
            r = mid;
            continue;
        }
        ll num = (R-mid)/(x-1)+(B-mid)/(y-1);
        if(num >= mid){
            l = mid;
        }else{
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}