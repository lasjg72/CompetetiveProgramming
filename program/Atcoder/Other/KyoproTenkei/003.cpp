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
int u, v, num, tmp;

void dfs(int x, int p = -1, int a = 0){
    bool ok = true;
    for(int to : g[x]){
        if(p == to) continue;
        if(ok) a++;
        ok = false;
        dfs(to, x, a);
    }
    if(ok) {
        if(num <= a){
            num = a;
            tmp = x;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    g.resize(n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0);
    u = tmp;
    //cout << "u: " << u << endl;
    num = 0;
    tmp = 0;
    dfs(u);
    cout << num+1 << endl;
    return 0;
}