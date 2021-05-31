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
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = 1001001001001001001;
    for(int bit = 0; bit < (1<<(n-1)); bit++){
        int num = 1;
        for(int i = 0; i < n-1; i++){
            if(bit&(1<<i)) num++;
        }
        if(num != k) continue;
        ll t = a[0];
        ll tmp = 0;
        for(int i = 0; i < n-1; i++){
            if(bit&(1<<i)){
                if(a[i+1] > t){
                    t = max(a[i+1], t);
                }else{
                    tmp += t-a[i+1]+1ll;
                    t = max(t+1, a[i+1]);
                }
            }else{
                t = max(t, a[i+1]);
            }
        }
        ans = min(tmp, ans);
    }
    cout << ans << endl;
    return 0;
}