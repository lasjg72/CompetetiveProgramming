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

int n;
vector<vector<int>> g;
vector<int> depth, dnum;

void dfs(int v, int p, int d){
    depth[v-1] = d;
    for(int u : g[v]){
        if(u == p) continue;
        dfs(u, v, d+1);
    }
}

int main()
{
    cin >> n;
    g.resize(n);
    depth.resize(n);
    dnum.resize(n);
    vector<int> P(n);
    for(int i = 1; i < n; i++){
        cin >> P[i];
        P[i]--;
    }
    dfs(0, -1, 0);
    for(int i = 0; i < n; i++){
        dnum[depth[i]]++;
    }

    int q;
    cin >> q;
    while(q--){
        int u, d;
        cin >> u >> d;
        if(depth[u] > d){
            cout << 0 << endl;
        }else{
            cout << dnum[d] << endl;
        }
    }
    return 0;
}