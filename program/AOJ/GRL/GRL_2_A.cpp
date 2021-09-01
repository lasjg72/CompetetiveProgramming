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

struct Edge{
    int from;
    int to;
    int co;
    Edge(int from, int to, int co):from(from), to(to), co(co){}
};

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
    bool same(int x, int y) { return root(x) == root(y);}
    int size(int x) { return -par[root(x)];}
};
using P = pair<int, int>;

bool comp(Edge& e1, Edge& e2){
    return e1.co < e2.co;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> e;
    UnionFind uf(n);
    for(int i = 0; i < m; i++){
        int s, t, c;
        cin >> s >> t >> c;
        e.emplace_back(s, t, c);
        //uf.unite(s, t);
    }
    sort(e.begin(), e.end(), comp);
    ll ans = 0;
    for(int i = 0; i < m; i++){
        int s = e[i].from;
        int t = e[i].to;
        if(uf.same(s, t)) continue;
        uf.unite(s, t);
        ans += e[i].co;
    }
    cout << ans << endl;
    return 0;
}