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
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    vector<ll> numb(n);
    for(int i = 0; i < n; i++){
        int l = -1, r = n-1;
        while(r-l > 1){
            int mid = (r+l)/2;
            if(c[mid] > b[i]){
                r = mid;
            }else{
                l = mid;
            }
        }
        if(b[i] < c[r]){
            numb[i] += n-r;
        }
    }
    vector<ll> sum(n+1, 0);
    for(int i = 0; i < n; i++){
        sum[i+1] = numb[i] + sum[i];
        //cout << "sum: " << sum[i+1] << endl;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int l = -1, r = n-1;
        while(r-l > 1){
            int mid = (r+l)/2;
            if(b[mid] > a[i]){
                r = mid;
            }else{
                l = mid;
            }
        }
        //cout << "r: " << r << endl;
        if(a[i] < b[r]) ans += sum[n]-sum[r];
    }
    cout << ans << endl;
    return 0;
}