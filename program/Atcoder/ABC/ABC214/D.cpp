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
ll ans = 0;

struct UnionFind {
    vector<ll> par;
    UnionFind (ll n) : par(n, -1){}
    ll root(ll x){
        if(par[x] < 0) return x;
        return par[x] = root(par[x]);
    }
    bool unite(ll x, ll y){
        x = root(x), y = root(y);
        if(x == y) return false;
        if(par[x] > par[y]) swap(x,y);
        par[x] += par[y]; 
        par[y] = x;
        return true;
    }
    bool same(int x, int y){
        return root(x) == root(y);
    }
    ll size(ll x) {
        return -par[root(x)];
    }
};

using P = pair<ll, ll>;

int main()
{
    int n;
    cin >> n;
    vector<pair<ll, P>> p;
    for(int i = 0; i < n-1; i++){
        ll a, b; 
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        p.push_back({c, {a, b}});
    }
    sort(p.begin(), p.end());
    UnionFind uf(n);
    for(int i = 0; i < n-1; i++){
        ll x = p[i].second.first;
        ll y = p[i].second.second;
        ll num = uf.size(x)*uf.size(y);
        ans += num*p[i].first;
        uf.unite(x, y);
    }
    cout << ans << endl;
    return 0;
}