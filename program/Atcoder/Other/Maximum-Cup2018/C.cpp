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
vector<int> col;

bool dfs(int x){
    for(int to: g[x]){
        if(col[to] != 0 && col[to] == col[x]) return false;
        if(col[to] != 0) continue;
        col[to] = 3-col[x];
        if(!dfs(to)) return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    g.resize(n);
    col.resize(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
        g[i].push_back(a[i]);
        g[a[i]].push_back(i);
    }
    for(int i = 0; i < n; i++){
        if(col[i] == 0){
            col[i] = 1;
            if(!dfs(i)){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << n/2 << endl;
    return 0;
}