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
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
    }

    vector<ll> c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    vector<ll> sum(n,0), num(n, 0), mx(n, 0);

    ll ans = -1e18;

    for(int i = 0; i < n; i++){
        int now = i;
        ll tot = 0;
        vector<ll> s;
        while(1){
            now = p[now];
            tot += c[now];
            s.push_back(c[now]);
            num[i]++;
            if(now == i) break;
        }
        ll t = 0;
        for(int j = 0; j < num[i]; j++){
            t += s[j];
            ll tmp = t;
            if(j + 1 > k) break;
            if(tot > 0){
                ll e = (k-(j+1)) / num[i];
                tmp += tot * e;
            }
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;
    return 0;
}