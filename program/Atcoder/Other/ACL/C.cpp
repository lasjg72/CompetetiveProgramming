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

struct Unionfind{
    vector<int> par;
    Unionfind(int n):par(n, -1){};
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
    bool same(int x, int y){return root(x) == root(y);}
};

int main()
{
    int n, m;
    cin >> n >> m;
    Unionfind uf(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        uf.unite(a, b);
    }
    set<int> a;
    for(int i = 0; i < n; i++){
        a.insert(uf.root(i));
    }
    cout << a.size()-1 << endl;
    return 0;
}