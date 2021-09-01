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

int dfs(int x){
    int mx = 0, mi = 1001001001;
    if(g[x].size() == 0) return 1;
    for(int to : g[x]){
        int now = dfs(to);
        mx = max(mx, now);
        mi = min(mi, now);
    }
    return mx+mi+1;
}

int main()
{
    int n;
    cin >> n;
    g.resize(n);
    for(int i = 0; i < n-1; i++){
        int a;
        cin >> a;
        a--;
        g[a].push_back(i+1);
    }
    cout << dfs(0) << endl;
    return 0;
}