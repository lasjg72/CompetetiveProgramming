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

ll n;
vector<ll> h, s;

bool func(ll mid){
    ll now;
    vector<ll> cnt(n, 0);
    for(int i = 0; i < n; i++){
        if(mid < h[i]){
            return false;
        }else{
            now = min(n-1, (mid-h[i])/s[i]);
            cnt[now]++;
        }
    }
    for(int i = 0; i < n-1; i++) cnt[i+1] += cnt[i];
    for(int i = 0; i < n; i++){
        if(i+1 < cnt[i]) return false;
    }
    return true;
}

int main()
{
    cin >> n;
    h.resize(n);
    s.resize(n);
    for(int i = 0; i < n; i++){
        cin >> h[i] >> s[i];
    }
    ll l = -1, r = 1e18;
    ll mid;
    while(r-l > 1){
        mid = (l+r)/2;
        if(func(mid)){
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << r << endl;
    return 0;
}

