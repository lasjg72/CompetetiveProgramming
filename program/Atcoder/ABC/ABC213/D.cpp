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
int n;
vector<priority_queue<int, vector<int>, greater<int>>> to;
vector<int> ans, past;
vector<bool> used;

void dfs(int u){
    ans.push_back(u);
    bool ok = true;
    //cout << "u: " << u << endl;
    while(!to[u].empty()){
        int v = to[u].top(); to[u].pop();
        //cout << "v: " << v << endl;
        if(used[v]) continue;
        past[v] = u;
        ok = false;
        used[v] = true;
        dfs(v);
        break;
    }
    if(ok){
        if(u == 0){
            return;
        }else{
            dfs(past[u]);
        }
    }
}

int main()
{
    cin >> n;
    to.resize(n);
    used.resize(n, false);
    past.resize(n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push(b);
        to[b].push(a);
    }
    used[0] = true;
    dfs(0);
    
    for(int v : ans){
        cout << v+1 << " ";
    }
    cout << endl;
    return 0;
}