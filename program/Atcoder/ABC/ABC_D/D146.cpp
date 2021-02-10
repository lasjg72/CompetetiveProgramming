#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

struct Edge{
    int to, id;
};

int n;
vector<vector<Edge>> G;
vector<int> ans;

void dfs(int v, int pre = -1, int p = -1){
    int color = 1;
    for(int i = 0; i < G[v].size(); i++){
        int u = G[v][i].to;
        int ei = G[v][i].id;
        if(u == p) continue;
        if(pre == color) color++;
        
        ans[ei] = color;
        color++;
        dfs(u, ans[ei], v);
    }
}

int main()
{
    cin >> n;
    G.resize(n);
    ans.resize(n-1);
    for(int i = 0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back((Edge){b, i});
        G[b].push_back((Edge){a, i});
    }
    dfs(0);

    int an = 0;
    for(int i = 0; i< n; i++){
        int tmp = G[i].size();
        an = max(an, tmp);
    }
    cout << an << endl;
    for(int i = 0; i < n-1; i++){
        cout << ans[i] << endl;
    }
    return 0;
}