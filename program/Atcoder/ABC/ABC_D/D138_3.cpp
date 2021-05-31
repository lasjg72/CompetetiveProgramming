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
int ans[200005];
vector<vector<int>> g;

void dfs(int v, int p, int val){
    // cout << "v: " << v << endl;
    // cout << "val: " << val << endl;
    ans[v] += val;
    for(int u : g[v]){
        if(u == p) continue;
        dfs(u, v, ans[v]);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    g.resize(n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    while(q--){
        int p, x;
        cin >> p >> x;
        p--;
        ans[p] += x;
    }
    dfs(0, -1, 0);
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}