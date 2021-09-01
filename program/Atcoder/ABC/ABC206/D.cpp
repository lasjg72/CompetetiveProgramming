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

int n, ans;
vector<vector<int>> g;
vector<int> used;

void dfs(int x){
    used[x] = true;
    for(int to : g[x]){
        if(used[to]) continue;
        dfs(to);
    }
    ans++;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    used.resize(200005, false);
    g.resize(200005);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < (n+1)/2; i++){
        if(a[i] == a[n-1-i]) continue;
        g[a[i]].push_back(a[n-1-i]);
        g[a[n-1-i]].push_back(a[i]);
    }
    for(int i = 0; i < n; i++){
        if(used[a[i]]) continue;
        dfs(a[i]);
        ans -= 1;
    }
    cout << ans << endl;
    return 0;
}