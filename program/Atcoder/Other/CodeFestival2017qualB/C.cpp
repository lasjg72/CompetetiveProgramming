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
const int mod = 1000000007;

vector<vector<int>> g;
vector<int> used, col;
ll pos = -1, na = 0, nb = 0;
bool ok;

void dfs(int x){
    for(int to: g[x]){
        if(col[to] != 0 && col[to] == col[x]) ok = false;
        if(col[to] != 0) continue;
        col[to] = 3-col[x];
        dfs(to);
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n);
    col.resize(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ok = true;
    col[0] = 1;
    dfs(0);
    if(ok){
        for(int i = 0; i < n; i++){
            if(col[i] == 1) na++;
            else nb++;
        }
        cout << na*nb-m << endl;
        return 0;
    }else{
        cout << n*(n-1)/2-m << endl;
        return 0;
    }
    return 0;
}
