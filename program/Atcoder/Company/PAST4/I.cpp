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
    vector<ll> sum(n+1, 0), a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum[i+1] = a[i] + sum[i];
    }
    ll ans = 1e10;
    int right = 0;
    for(int left = 0; left < n; left++){
        ll x = sum[right+1] - sum[left];
        ll y = sum[n] - x;
        //cout << x << " " << y << endl;
        ll tmp = abs(y-x);
        ans = min(ans, tmp);
        //cout << "ans1: " << ans << endl;
        ll prev = tmp;
        while(right < n){
            right++;
            if(right == n) {
                right--;
                break;
            }
            ll nx = sum[right+1] - sum[left];
            ll ny = sum[n] - nx;
            if(prev < abs(ny-nx)){
                right--;
                break;
            }else{
                ans = min(ans, abs(ny-nx));
                prev = abs(ny-nx);
                //cout << "ans2: " << ans << endl;
            }
            //ans = min(ans, abs(ny-nx));
            //cout << "ans2: " << ans << endl;
        }
    }
    cout << ans << endl;
    return 0;
}