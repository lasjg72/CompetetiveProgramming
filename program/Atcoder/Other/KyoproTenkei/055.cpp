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
    int n, p, q;
    cin >> n >> p >> q;
    vector<ll> a(n);
    ll ans = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int n1 = 0; n1 < n-4; n1++){
        for(int n2 = n1+1; n2 < n-3; n2++){
            if(n1 == n2) continue;
            for(int n3 = n2+1; n3 < n-2; n3++){
                if(n2 == n3 || n1 == n3) continue;
                for(int n4 = n3+1; n4 < n-1; n4++){
                    if(n1 == n4 || n2 == n4 || n3 == n4) continue;
                    for(int n5 = n4+1; n5 < n; n5++){
                        if(n1 == n5 || n2 == n5 || n3 == n5 || n4 == n5) continue;
                        ll now = a[n1]*a[n2]%p;
                        now = now*a[n3]%p;
                        now = now*a[n4]%p;
                        now = now*a[n5]%p;
                        if(now == q) ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}