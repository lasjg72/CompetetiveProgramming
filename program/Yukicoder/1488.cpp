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

struct edge{
    int to;
    int co;
    edge(int to, int co):to(to), co(co){};
};

int x, y, tot;
vector<vector<edge>> g;

void dfs(int v, int p = -1){
    for(edge e: g[v]){
        if(e.to == p) continue;
        tot += e.co;
        dfs(to, x);
    }
}

void dfs2(){
    
}

int main()
{
    int n, k;
    cin >> n >> k;
    g.resize(n);
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            x = i; 
            y = j;
            tot = 0;
            dfs(0);
            ans = max(ans, tot);
        }
    }
    cout << ans << endl;
    return 0;
}