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

struct UnionFind {
    vector<int> par;
    UnionFind (int n) : par(n, -1){}
    int root(int x){
        if(par[x] < 0) return x;
        return par[x] = root(par[x]);
    }
    bool unite(int x, int y){
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
    int size(int x) {
        return -par[root(x)];
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    UnionFind uf(200005);
    for(int i = 0; i < n; i++) uf.unite(a[i], a[n-1-i]);
    int ans = 0;
    for(int i = 0; i < 200005; i++) if(uf.root(i) == i) ans += uf.size(i)-1;
    cout << ans << endl;
    return 0;
}