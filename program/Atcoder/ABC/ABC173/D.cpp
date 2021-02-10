#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll mx= 0, max2=0;
    priority_queue<ll> q;
    for(ll i = 0; i< n; i++){
        cin >> a[i];
        q.push(a[i]);
    }
    mx = q.top();
    q.pop();
    
    ll ans = mx;
    ll num;
    if(n % 2 != 0){
        for(ll i = 0; i < (n-1)/2; i++){
        int now = q.top();
        q.pop();
        ans += now*2;
        if(i == (n-1)/2-1){
            ans -= now;
        }
    }
    }else{
        for(ll i = 0; i < (n-1)/2; i++){
            int now = q.top();
            q.pop();
            ans += now*2;
        }
    }
    
    cout << ans << endl;
    return 0;
}