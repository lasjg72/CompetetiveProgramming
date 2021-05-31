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

// struct E{
//     int to;
//     int co;
//     E(int to, int xco):to(to), co(co){}
// };

struct Edge{
    int u;
    int v;
    int co;
    Edge(int u, int v, int co) : u(u), v(v), co(co){}
};

bool comp(const Edge& e1, const Edge& e2){
    return e1.co < e2.co;
}

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
    //vector<vector<E>> g(n);
    vector<Edge> edge;
    UnionFind par(n);
    for(int i = 0; i < n-1; i++){
        //g[x[i].second].emplace_back(x[i+1].second, abs(x[i].first-x[i+1].first));
        //g[y[i].second].emplace_back(y[i+1].second, abs(y[i].first-y[i+1].first));
        edge.emplace_back(x[i].second, x[i+1].second, abs(x[i].first-x[i+1].first));
        edge.emplace_back(y[i].second, y[i+1].second, abs(y[i].first-y[i+1].first));
    }
    sort(edge.begin(), edge.end(), comp);
    int ans = 0;
    for(Edge e : edge){
        if(par.same(e.u, e.v)) continue;
        //cout << "test" << endl;
        ans += e.co;
        par.unite(e.u, e.v);
    }
    cout << ans << endl;
    return 0;
}