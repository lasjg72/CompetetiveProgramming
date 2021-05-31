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
vector<int> used;

void dfs(int x, int p){
    for(int to : g[x]){
        if(to == p) continue;
        used[to] = (used[x]+1)%2;
        dfs(to, x);
    }
}

int main()
{
    int n;
    cin >> n;
    g.resize(n);
    used.resize(n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1);
    int a = 0, b = 0;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(used[i]) a++;
        else b++;
    }
    if(a >= n/2){
        for(int i = 0; i < n; i++){
            if(used[i]) ans.push_back(i);
            if(ans.size() == n/2) break;
        }
    }else{
        for(int i = 0; i < n; i++){
            if(!used[i]) ans.push_back(i);
            if(ans.size() == n/2) break;
        }
    }
    for(int i: ans) cout << i+1 << " ";
    cout << endl;
    return 0;
}