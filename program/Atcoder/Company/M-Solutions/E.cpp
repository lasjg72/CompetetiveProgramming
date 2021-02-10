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
    vector<ll> a(n+2);
    for(ll i = 0; i< n; i++){
        cin >> a[i];
    }
    ll num = 0, sum = 1000;
    ll i = 0;
    while(i < n-1){
        ll mx= 0, mi = 1001001001;
        if(i+1 < n && a[i] <= a[i+1]){
            if(i!=0){
                while(a[i] <= a[i+1]){
                    mx = max(a[i+1], mx);
                    i += 1;
                    if(i == n-1) break;
                }
                sum += num * mx;
                num = 0;
            }else if(i == 0){
                num += 1000 / a[i];
                sum -= a[i]*num;
                i += 1;
            }
            // cout << "sum: " << sum << endl;
            // cout << "num: " << num << endl;
        }else if(i+1 < n && a[i] > a[i+1]){
            if(num > 0){
                sum += num * a[i];
                num = 0;
            }
            while(a[i] > a[i+1]){
                mi = min(a[i+1], mi);
                i += 1;
                if(i == n-1) break;
            }
            num += sum / mi;
            sum -= num * mi;
            // cout << "sum: " << sum << endl;
            // cout << "num: " << num << endl;
        } 
    }
    if(num > 0){
        sum += num * a[n-1];
    }
    cout << sum << endl;
    return 0;
}