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

// int dfs(int n, int p, int d, int s){
//     bool ok = false;
//     for(int to : g[n]){
//         if(d == 2 && to != s){
//             ok = true;
//             continue;
//         }else if(d == 2 && to == s){
//             ok = false;
//             break;
//         }
//         if(to == p) continue;
//         dfs(to, n, d+1, s);
//     }
//     if(ok) return 1;
//     return 0;
// }

int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // for(int i = 0; i < n; i++){
    //     int ans = 0;
    //     ans += dfs(i, -1, 0, i);
    //     cout << ans << endl;
    // }
    for(int i = 0; i < n; i++){
        set<int> ans;
        for(int to1 : g[i]){
            for(int to2 : g[to1]){
                if(to2 == i) continue;
                bool ok = true;
                for(int to3 : g[to2]){
                    if(to3 == to1) continue;
                    if(to3 == i) ok = false;
                }
                if(ok) ans.insert(to2);
            }
        }
        cout << ans.size() << endl;
    }
    return 0;
}