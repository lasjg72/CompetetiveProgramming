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
#include <numeric>

using namespace std;
using ll = long long;

int n;

struct UnionFind{
    vector<int> par;
    UnionFind(int x) : par(x, -1){};
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
    bool same(int x, int y){
        return root(x) == root(y);
    }
};

int main()
{
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<int> b(n);
    iota(b.begin(), b.end(), 0);
    UnionFind uf(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    int m;
    cin >> m;
    vector<int> x(m), y(m);
    for(int i = 0; i < m; i++){
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }
    ll ans = 1001001001;
    do{
        bool ok = true;
        ll tmp = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < m; j++){
                if(x[j] == b[i] && y[j] == b[i+1]){
                    ok = false;
                    break;
                }
                if(x[j] == b[i+1] && y[j] == b[i]){
                    ok = false;
                    break;
                }
            }
        }
        if(ok){
            for(int j = 0; j < n; j++){
                //cout << "b[j]: " << b[j] << " j: " << j << endl;
                tmp += a[b[j]][j];
            }
            ans = min(ans, tmp);
        }
    }while(next_permutation(b.begin(), b.end()));
    if(ans == 1001001001) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}