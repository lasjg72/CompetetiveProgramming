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

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

using P = pair<ll, ll>;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    vector<ll> c(m);
    int tmp = n;
    for(int i = 0; i < m; i++){
        cin >> a[i] >> c[i];
        tmp = gcd(tmp, a[i]);
    }
    if(tmp != 1){
        cout << -1 << endl;
        return 0;
    }
    vector<P> nc(m);
    for(int i = 0; i < m; i++){
        nc[i].first = ((n-1)-(a[i]-1))*c[i];
        nc[i].second = i;
    }
    sort(nc.begin(), nc.end());
    ll ans = nc[0].first;
    int now = nc[0].second;
    vector<P> nnc(m);
    for(int i = 0; i < m; i++){
        nnc[i].first = c[i];
        nnc[i].second = i;
    }
    sort(nnc.begin(), nnc.end());
    for(int i = 0; i < m; i++){
        if(nnc[i].second == now) continue;
        if(gcd(a[now], a[nnc[i].second]) == 1) {
            ans += (a[now]-1)*nnc[i].first;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}