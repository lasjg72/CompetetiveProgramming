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

struct UniondFind{
    vector<int> par;
    UniondFind(int n):par(n,-1){};
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
    bool same(int x, int y){ return root(x) == root(y);}
};

int main()
{
    int h, w;
    cin >> h >> w;
    int q;
    cin >> q;
    int x[4] = {0, 1, 0, -1};
    int y[4] = {1, 0, -1, 0};
    vector<vector<char>> s(h, vector<char>(w, '.'));
    UniondFind uf(h*w);
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int r, c;
            cin >> r >> c;
            r--; c--;
            int now = r*w + c;
            s[r][c] = 'R';
            for(int i = 0; i < 4; i++){
                int n2 = (r+x[i])*w + c + y[i];
                if(r+x[i] < 0 || r+x[i] >= h || c+y[i] < 0 || c+y[i] >= w) continue;
                if(s[r+x[i]][c+y[i]] == 'R') uf.unite(now, n2);
            }
        }else{
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            r1--; c1--; r2--; c2--;
            // cout << "r1*w+c1: " << r1*w+c1 << endl;
            // cout << "r2*w+c2: " << r2*w+c2 << endl;
            if(uf.same(r1*w+c1, r2*w+c2) && s[r1][c1] == 'R' && s[r2][c2] == 'R'){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
    return 0;
}