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
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a), t(b);
    for(int i = 0; i < a; i++) cin >> s[i];
    for(int i = 0; i < b; i++) cin >> t[i];
    while(q--){
        ll x;
        cin >> x;
        int sn = lower_bound(s.begin(), s.end(), x)-s.begin();
        int tn = lower_bound(t.begin(), t.end(), x)-t.begin();
        //cout << sn << " tn: " << tn << endl;
        ll ans = 1LL<<60;
        for(int i = max(sn-1, 0); i <= min(sn, a-1); i++){
            for(int j = max(tn-1, 0); j <= min(tn, b-1); j++){
                ll tmp = min(abs(s[i]-x)+abs(s[i]-t[j]), abs(t[j]-x)+abs(s[i]-t[j]));
                ans = min(ans, tmp);
            }
        }
        cout << ans << endl;
    }
    return 0;
}