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
    vector<int> par;
    UnionFind(int n): par(n,-1){};
    
    int root(int x){
        if(par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    bool unite(int x, int y){
        x = root(x);
        y = root(y);
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
    int n, q;
    cin >> n >> q;
    UnionFind uf(2*n);
    while(q--){
        int w, x, y, z;
        cin >> w >> x >> y >> z;
        x--; y--;
        if(w == 1){
            if(z%2==0){
                uf.unite(x, y);
                uf.unite(x+n, y+n);
            }else{
                uf.unite(x, y+n);
                uf.unite(x+n, y);
            }
        }else{
            if(uf.same(x, y)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}