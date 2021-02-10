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
    vector<int> siz;

    UnionFind(int N) : par(N){
        siz = vector<int>(N, 1);
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x){
        if(par[x] == x) return x;
        return x = root(par[x]);
    }

    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(siz[x] < siz[y]) swap(x,y);
        siz[x] += siz[y];
        par[y] = x;
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }

    int size(int x){
        return siz[root(x)];
    }

};

int main()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;

    UnionFind tree(n);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        tree.unite(a, b);
    }
    for(int i = 0; i < n; i++){
        ans = max(ans, tree.size(i));
    }

    // for(int i = 0; i < m; i++){
    //     int a, b;
    //     cin >> a >> b;
    //     a--; b--;
    //     if(fri[a].size() != 0) {
    //         //cout << "a" << endl;
    //         fri[a].push_back(b);
    //         fri[b].push_back(a);
    //         ans = max(ans, (int)fri[a].size()+1);
    //         ans = max(ans, (int)fri[b].size()+1);
    //     }
    //     else if(fri[b].size() != 0) {
    //         //cout << "b" << endl;
    //         fri[a].push_back(b);
    //         fri[b].push_back(a);
    //         //cout << "fri[b].size(): " << fri[b].size() << endl;
    //         ans = max(ans, (int)fri[b].size()+1);
    //         ans = max(ans, (int)fri[a].size()+1);
    //     }
    //     else {
    //         //cout << "c" << endl;
    //         fri[a].push_back(b);
    //         fri[b].push_back(a);
    //         ans = max(ans, (int)fri[a].size()+1);
    //         ans = max(ans, (int)fri[b].size()+1);
    //     }
    // }

    cout << ans << endl;
    return 0;
}