#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

struct UnionFind {
    vector<int> par;
    UnionFind (int n) : par(n, -1){}
    int root(int x){
        if(par[x] < 0) return x;
        return root(par[x]);
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

//vector<int> block[100005];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    UnionFind uf(n);
    vector<int> deg(n, 0);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        deg[a]++;
        deg[b]++;
        uf.unite(a, b);
    }
    vector<int> block[n];
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        //cout << a << b << endl;
        block[a].push_back(b);
        block[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        int ans = uf.size(i)-1-deg[i];
        for(int v : block[i]){
            if(uf.same(i, v)){
                ans--;
            }
        }
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}