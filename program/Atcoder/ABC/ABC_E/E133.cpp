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
ll ans, k;
const int mod = 1e9+7;

void dfs(int u, int p = -1, int num = k){
    ans = ans*num%mod;
    if(p == -1) num = k-1;
    else num = k-2;
    for(int to: g[u]){
        if(to == p) continue;
        dfs(to, u, num);
        num--;
    }
}

int main()
{
    int n;
    cin >> n >> k;
    ans = 1;
    g.resize(n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    if(ans < 0) ans = 0;
    cout << ans << endl;
    return 0;
}