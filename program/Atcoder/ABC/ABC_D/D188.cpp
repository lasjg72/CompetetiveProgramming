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
using P = pair<ll, ll>;

int main()
{
    ll n, C;
    cin >> n >> C;
    vector<P> p;
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        p.push_back(P(a, c));
        p.push_back(P(b+1, -c));
    }
    sort(p.begin(), p.end());
    ll ans = 0, t = 0, nc = 0;
    for(P now : p){
        ll x = now.first;
        ll y = now.second;
        if(x != t){
            ans += min(C, nc)*(x-t);
        }
        t = x;
        nc += y;
    }
    cout << ans << endl;
    return 0;
}