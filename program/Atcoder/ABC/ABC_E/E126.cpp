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

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int a, b, z;
        cin >> a >> b >> z;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<bool> used(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(used[i]) continue;
        ans++;
        queue<int> q;
        q.push(i);
        used[i] = true;
        while(!q.empty()){
            int now = q.front(); q.pop();
            for(int to : g[now]){
                if(used[to]) continue;
                used[to] = true;
                q.push(to);
            }
        }
    }
    cout << ans << endl;
    return 0;
}