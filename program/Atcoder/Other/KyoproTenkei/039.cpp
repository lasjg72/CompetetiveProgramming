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

const int INF = 1001001001;
ll c[100005];
vector<vector<int>> g;
ll ans;
ll n;

int dfs(int x, int p = -1){
    bool leaf = true;
    //cout << "x: " << x << " p: " << p << endl;
    for(int to : g[x]){
        if(to == p) continue;
        leaf = false;
        c[x] += dfs(to, x);
    }
    if(leaf) c[x] = 1;
    else c[x]++;
    return c[x];
}

void dfs2(int x, int p = -1){
    for(int to : g[x]){
        if(to == p) continue;
        //cout << "x: " << x << " to: " << to << " c[to]: " << c[to] << endl;
        ans += c[to]*(n-c[to]);
        dfs2(to, x);
    }
}

int main()
{
    cin >> n;
    g.resize(n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    dfs2(0);
    cout << ans << endl;
    return 0;
}