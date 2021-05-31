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
    vector<int> g[n];
    vector<vector<bool>> res(n, vector<bool>(n, false));
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        res[a][b] = true;
        res[b][a] = true;
    }
    ll ans = m;
    for(int i = 0; i < n; i++){
        for(int v: g[i]){
            // cout << "---" << endl;
            // cout << "i: " << i << endl;
            // cout << "v: " << v << endl;
            vector<bool> mark(n, false);
            if(res[i][v]){
                res[i][v] = false;
                res[v][i] = false;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int now = q.front();
                    q.pop();
                    for(int s: g[now]){
                        // cout << "now: " << now << endl;
                        // cout << "s: " << s << endl;
                        if((s == i && now == v) || (s == v && now == i)) continue;
                        else if(!mark[s]){
                            //cout << "if in" << endl;
                            mark[s] = true;
                            q.push(s);
                            if(s == v) ans--;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}