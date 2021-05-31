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
    UnionFind(int x) : par(x, -1){};

    int root(int x){
        if(par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    bool same(int x, int y){
        return root(x) == root(y);
    }
    bool unite(int x, int y){
        if(root(x) == root(y)) return false;
        x = root(x); y = root(y);
        if(x > y) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    int size(int x){ return -par[root(x)]; }

};

int rel[12][12];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        rel[x][y] = 1;
        rel[y][x] = 1;
    }

    int ans = 1;
    for(int bit = 0; bit < (1<<n); bit++){
        vector<int> a(n, 0);
        bool ok = false;
        int tmp = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if((bit&(1<<i)) && (bit&(1<<j)) && rel[i][j] > 0){
                    a[i]++;
                    a[j]++;
                }else if((bit&(1<<i)) && (bit&(1<<j)) && rel[i][j] == 0){
                    ok = true;
                }
            }
            if(ok) break;
        }
        if(ok) continue;
        for(int j = 0; j < n; j++){
            if(a[j] > 0) tmp++;
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}