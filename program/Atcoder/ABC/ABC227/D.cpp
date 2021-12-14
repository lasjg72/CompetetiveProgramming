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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ok = 0, ng = 1e18;
    while(ng-ok>1){
        ll sum = 0, mid = (ok+ng)/2;
        for(int i = 0; i < n; i++){
            sum += min(a[i], mid);
        }
        if(sum/k >= mid){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}