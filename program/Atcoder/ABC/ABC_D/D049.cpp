#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

struct UnionFind{

    vector<int> par;

    UnionFind(int N) : par(N){
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x){
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return ;
        par[rx] = ry;
    }

    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

};

int main()
{
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> p(k), q(k), r(l), s(l);
    map<int, int> ans, path, train;
    UnionFind tree1(n), tree2(n);
    
    for(int i = 0; i < k; i++){
        cin >> p[i] >> q[i];
        tree1.unite(p[i]-1, q[i]-1);
    }

    for(int i = 0; i < l; i++){
        cin >> r[i] >> s[i];
        tree2.unite(r[i]-1, s[i]-1);
    }

    map<pair<int, int>, int> pa;
    for(int i = 0; i < n; i++){
        pa[{tree1.root(i), tree2.root(i)}]++;
    }
    for(int i = 0; i < n; i++){
        cout << pa[{tree1.root(i), tree2.root(i)}] << endl;
    }
    return 0;
}