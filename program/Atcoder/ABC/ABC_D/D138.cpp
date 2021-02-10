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

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

vector<vector<int>> G;

void dfs(int v, int p, vector<ll>& val){
    if(p != -1) val[v] += val[p];
    for(int i = 0; i < G[v].size(); i++){
        if(G[v][i] == p) continue;
        dfs(G[v][i], v, val);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    G.resize(n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> val(n);
    for(int i = 0; i < q; i++){
        int p, x;
        cin >> p >> x;
        p--;
        val[p] += x;
    }
    dfs(0, -1, val);
    for(auto v: val) cout << v << " ";
    cout << endl;
    return 0;
}