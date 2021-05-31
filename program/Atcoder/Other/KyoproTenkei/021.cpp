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
vector<bool> used;
vector<vector<int>> g, rg, scc;
vector<int> vs;

void dfs(int x){
    //cout << "dfs1" << endl;
    used[x] = true;
    for(int to : g[x]){
        if(used[to]) continue;
        dfs(to);
    }
    vs.push_back(x);
}

void dfs2(int x, int k){
    //cout << "dfs2" << endl; 
    used[x] = true;
    scc[k].push_back(x);
    for(int to: rg[x]){
        if(used[to]) continue;
        dfs2(to, k);
    }

}

int main()
{
    int n, m;
    cin >> n >> m;
    used.resize(n);
    g.resize(n);
    rg.resize(n);
    scc.resize(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    for(int i = 0; i < n; i++) {
        if(used[i]) continue;
        dfs(i);
    }
    fill(used.begin(), used.end(), false);
    int k = 0;
    for(int i = vs.size()-1; i >= 0; i--){
        if(used[vs[i]]) continue;
        dfs2(vs[i], k++);
    }
    ll ans = 0;
    for(vector<int> res : scc){
        //cout << "res.size(): " << res.size() << endl;
        ans += res.size()*(res.size()-1)/2;
    }
    cout << ans << endl;
    return 0;
}