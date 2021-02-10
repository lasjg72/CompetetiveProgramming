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
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m), sa(n+1, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sa[i+1] = sa[i] + a[i];
    }
    vector<ll> s(m+1, 0);
    int maxb=-1; 
    for(int i = 0; i < m; i++){
        cin >> b[i];
        s[i+1] = s[i] + b[i];
        if(s[i+1] > k){
            maxb = i;
        }
    }
    if(maxb = -1) maxb = m;
    ll ans = 0, remain = k-s[maxb], maxa = 0;
    for(int i = 1; i < n+1; i++){
        if(remain < sa[i]) maxa = i-1;
    }
    remain -= sa[maxa];
    for(ll i = maxb-1; i >= 0; i--){
        remain += b[i];
        ll remain2 = remain;
        for(ll j = maxa+1; i < n; i++){
            remain2 -= a[j];
            if(remain2 < 0){
                ans = max(ans, i+j);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}