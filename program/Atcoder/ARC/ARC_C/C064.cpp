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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(i == 0){
            if(a[i] > x) {
                ans += a[i]-x;
                a[i] = x;
            }
        }else{
            if(a[i-1]+a[i] > x){
                ans += a[i-1]+a[i]-x;
                a[i] -= a[i-1]+a[i]-x;
            }
        }
    }
    cout << ans << endl;
    return 0;
}