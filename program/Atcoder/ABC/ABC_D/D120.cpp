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

struct UnionFind{
    vector<ll> par;
    UnionFind(int n):par(n, -1){};

    int root(int x){
        if(par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool unite(int x, int y){
        x = root(x); y = root(y);
        if(x == y) return false;
        if(par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    bool same(int x, int y){ return root(x)==root(y);}
    ll size(int x){ return -par[root(x)];}
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m);
    UnionFind uf(n);
    vector<ll> num;
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    ll ans = 1LL*n*(n-1)/2;
    for(int i = m-1; i >= 0; i--){
        num.push_back(ans);
        if(!uf.same(a[i], b[i])) ans -= uf.size(a[i])*uf.size(b[i]);
        uf.unite(a[i], b[i]);
    }
    reverse(num.begin(), num.end());
    for(int i = 0; i < m; i++){
        cout << num[i] << endl;
    }
    return 0;
}