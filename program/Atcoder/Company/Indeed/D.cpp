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

struct edge{
    int from;
    int to;
    ll cost;
    //edge(int from, int to, int cost):from(from), to(to), cost(cost){}
};

struct UnionFind{
    vector<ll> par;
    UnionFind(int n) : par(n, -1){};
    
    ll root(int x){
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
    ll size(int x){return -par[root(x)];}
    bool same(int x, int y){return root(x) == root(y);}
};

bool comp(const edge& e1, const edge& e2){
    return e1.cost < e2.cost;
}

int main()
{
    int h, w;
    cin >> h >> w;
    int sx, sy, gx, gy;
    cin >> sy >> sx >> gy >> gx;
    vector<edge> g;
    vector<vector<ll>> p(h, vector<ll>(w));
    int v = (h-1)*w+(w-1)*h;    
    UnionFind uf(h*w);
    ll ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> p[i][j];
            p[i][j] *= -1;
            ans += p[i][j];
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w-1; j++){
            //cout << i*w+j << " " << i*w+j+1 << " " << p[i][j]*p[i][j+1] << endl;
            g.push_back({i*w+j, i*w+j+1, -p[i][j]*p[i][j+1]});
        }
    }
    for(int i = 0; i < h-1; i++){
        for(int j = 0; j < w; j++){
            //cout << i*w+j << " " << i*w+j+w << " " << p[i][j]*p[i+1][j] << " " << endl;
            g.push_back({i*w+j, i*w+j+w, -p[i][j]*p[i+1][j]});
        }
    }
    sort(g.begin(), g.end(), comp);
    
    for(edge e : g){
        //edge e = g[i];
        int x = e.from, y = e.to;
        //cout << "x: " << x << " y: " << y << " cost: " << e.cost << endl;
        if(uf.same(x, y)) continue;
        uf.unite(x, y);
        ans += e.cost;
    }
    cout << -ans << endl;
    return 0;
}
