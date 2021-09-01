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

vector<vector<int>> to;
vector<int> ans;
void dfs(int u, int p = -1){
    ans.push_back(u);
    for(int v : to[u]){
        if(v == p) continue;
        dfs(v, u);
        ans.push_back(u);
    }
}

int main()
{
    int n;
    cin >> n;
    to.resize(n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    for(int i = 0; i < n; i++) sort(to[i].begin(), to[i].end());
    dfs(0);
    for(int i : ans){
        cout << i+1 << " ";
    }
    cout << endl;
    return 0;
}