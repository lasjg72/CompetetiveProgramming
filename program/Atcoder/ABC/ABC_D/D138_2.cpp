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
vector<int> pos, ans;

void dfs(int x, int p, int num){
    num += pos[x];
    ans[x] = num;
    for(int to : g[x]){
        if(to == p) continue;
        dfs(to, x, num);
    }
    return;
}

int main()
{
    int n, q;
    cin >> n >> q;
    g.resize(n);
    pos.resize(n);
    ans.resize(n);
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
        pos[p] += x;
    }
    dfs(0, -1, 0);
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}