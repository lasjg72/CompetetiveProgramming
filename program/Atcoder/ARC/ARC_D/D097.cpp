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
    int n, m;
    cin >> n >> m;

    UnionFind tree(n);

    vector<int> p(n);
    for(int i = 0; i< n; i++){
        cin >> p[i];
    }

    for(int i = 0; i< m; i++){
        int x, y;
        cin >> x >> y;
        tree.unite(x-1, y-1);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(tree.same(i, p[i]-1)) ans++;
    }
    cout << ans << endl;
    return 0;
}