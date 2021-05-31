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
using P = pair<int, int>;

struct UnionFind{
    vector<int> par;
    UnionFind(int n) : par(n, -1){}

    int root(int x){
        if(par[x] < 0) return x;
        return par[x] = root(par[x]);
    }

    bool unite(int x, int y){
        x = root(x); y = root(y);
        if(x == y) return false;
        if(par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    bool same(int x, int y){ return root(x) == root(y);}
};

int main()
{
    int n;
    cin >> n;
    vector<P> x(n), y(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        x[i] = {a, i};
        y[i] = {b, i};
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    ll ans = 0;
    UnionFind uf(n);
    vector<pair<ll, P>> e(2*n-2);
    for(int i = 0; i < n-1; i++){
        e[2*i].first = abs(x[i].first-x[i+1].first);
        e[2*i].second = {x[i].second, x[i+1].second};
        e[2*i+1].first = abs(y[i].first-y[i+1].first);
        e[2*i+1].second = {y[i].second, y[i+1].second};
    }
    sort(e.begin(), e.end());
    for(int i = 0; i < 2*n-2; i++){
        int nx = e[i].second.first;
        int ny = e[i].second.second;
        if(uf.same(nx, ny)) continue;
        int now = e[i].first;
        ans += now;
        uf.unite(nx, ny);
    }
    cout << ans << endl;
    return 0;
}