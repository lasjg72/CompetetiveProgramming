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

struct Edge{
    int from;
    int to;
    int co;
    Edge(int from, int to, int co): from(from), to(to), co(co){}
};

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

// bool comp(Edge& e1, Edge& e2){
//     return e1.co < e2.co;
// }

bool operator< (const Edge& e1, const Edge& e2){
    return e1.co > e2.co;
}

int main()
{
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    vector<vector<P>> g(n);
    vector<vector<int>> dist(n, vector<int>(n, -1));
    for(int i = 0; i < m; i++){
        int u, v, m;
        cin >> u >> v >> m;
        g[u].emplace_back(v, m);
        g[v].emplace_back(u, m);
        uf.unite(u, v);
        dist[u][v] = m;
        dist[v][u] = m;
    }
    int q;
    cin >> q;
    UnionFind nuf(n);
    set<int> v;
    vector<Edge> ne;
    priority_queue<Edge> que2;
    while(q--){
        int a, b;
        cin >> a >> b;
        int ans = 0;
        vector<int> edge1, edge2;
        v.insert(a);
        v.insert(b);
        for(int i = 0; i < n; i++){
            if(nuf.same(a, i)) edge1.emplace_back(i);
            else if(nuf.same(b, i))edge2.emplace_back(i);
        } 
        bool im = true;
        priority_queue<Edge> que = que2;
        for(int i = 0; i < edge1.size(); i++){
            for(int j = 0; j < edge2.size(); j++){
                nuf.unite(edge1[i], edge2[j]);
                if(dist[edge1[i]][edge2[j]] >= 0){
                    im = false;
                    que.emplace(edge1[i], edge2[j], dist[edge1[i]][edge2[j]]);
                    //ne.emplace_back(edge1[i], edge2[j], dist[edge1[i]][edge2[j]]);
                }
            }
        }

        //sort(ne.begin(), ne.end(), comp);
        UnionFind kra(n);
        //cout << "------" << endl;
        while(!que.empty()){
            Edge now = que.top(); que.pop();
            //cout << "cost: " << now.co << endl;
            if(kra.same(now.from, now.to)) continue;
            ans += now.co;
            kra.unite(now.from, now.to);
            que2.emplace(now.from, now.to, now.co);
        }
        if(im) cout << "IMPOSSIBLE" << endl;
        else {
            cout << ans << endl;
        }
    }
    return 0;
}