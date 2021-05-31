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
using P = pair<int, int>;
vector<vector<int>> g;
int num;
map<P, int> mp;

void dfs(int x, int c, int p){
    num = max(num, (int)g[x].size());
    int cur = 1;
    for(int to : g[x]){
        if(to == p) continue;
        if(cur == c) cur++;
        mp[{to, x}] = mp[{x, to}] = cur;
        dfs(to, cur, x);
        cur++;
    }
}

int main()
{
    int n;
    cin >> n;
    g.resize(n);
    vector<P> e(n-1);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        e[i] = {a, b};
    }
    dfs(0, -1, -1);
    cout << num << endl;
    for(int i = 0; i < n-1; i++){
        cout << mp[e[i]] << endl;
    }
    return 0;
}