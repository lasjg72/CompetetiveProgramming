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

vector<int> ans;
int c[100005];
vector<vector<int>> g;
int now[100005];

void dfs(int x, int p){
    if(now[c[x]] == 0) {
        ans.push_back(x);
    }
    now[c[x]]++;
    for(int to : g[x]){
        if(to != p) dfs(to, x);
    }
    now[c[x]]--;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    g.resize(n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    sort(ans.begin(), ans.end());
    for(int i : ans){
        cout << i+1 << endl;
    }
    return 0;
}