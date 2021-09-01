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
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        vector<bool> used(n, false);
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int to : g[u]){
                if(used[to]) continue;
                //cout << "i: " << i << " to: " << to << endl;
                q.push(to);
                used[to] = true;
                ans++;
            }
        }
        if(!used[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}