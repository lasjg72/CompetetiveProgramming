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

vector<vector<int>> g;
vector<int> col, vs;
vector<bool> used;
int tmp;

void dfs(int x){
    used[x] = true;
    vs.push_back(x);
    for(int to : g[x]){
        if(used[to]) continue;
        dfs(to);
    }
}

void dfs2(int i){
    if(i == vs.size()){
        tmp++;
        return;
    }
    int v = vs[i];
    for(int c = 0; c < 3; c++){
        bool ok = false;
        col[v] = c;
        for(int to: g[v]){
            if(col[to] == c) ok = true;
        }
        if(ok) continue;
        dfs2(i+1);
    }
    col[v] = -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    col.resize(n, -1);
    used.resize(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll ans = 1;
    
    for(int i = 0; i < n; i++){
        if(used[i]) continue;
        vs = vector<int>();
        dfs(i);
        col[vs[0]] = 0;
        tmp = 0;
        dfs2(1);
        ans *= tmp*3;
    }
    cout << ans << endl;
    return 0;
}