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

struct E{
    int to;
    int co;
    E(int to, int co) : to(to), co(co){}
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<E>> g(n);
    for(int i = 0; i < m; i++){
        int f, t, c;
        cin >> f >> t >> c;
        g[f].emplace_back(t, c);
        g[t].emplace_back(f, c);
    }
    const int INF = 1001001001;
    vector<vector<int>> dist4(n, vector<int>(4, INF));
    priority_queue<P, vector<P>, greater<P>> q;
    q.emplace(0, 0);
    dist4[0][0] = 0;
    while(!q.empty()){
        int nv = q.top().second;
        int nc = q.top().first;
        q.pop();
        if(dist4[nv][nc%4] != nc) continue;
        for(E e : g[nv]){
            //cout << "dist" << endl;
            if(dist4[e.to][(nc+e.co)%4] <= nc+e.co) continue;
            dist4[e.to][(nc+e.co)%4] = nc+e.co;
            if(e.to == n-1) continue;
            q.emplace(nc+e.co, e.to);
        }
    }
    // for(int i = 0; i < 4; i++){
    //     cout << "i: " << i << endl;
    //     for(int j = 0; j < n; j++){
    //         cout << dist4[i][j] << endl;
    //     }
    // }
    vector<vector<int>> dist7(n, vector<int>(7, INF));
    q.emplace(0, 0);
    dist7[0][0] = 0;
    while(!q.empty()){
        int nv = q.top().second;
        int nc = q.top().first;
        q.pop();
        if(dist7[nv][nc%7] != nc) continue;
        for(E e : g[nv]){
            if(dist7[e.to][(nc+e.co)%7] <= nc+e.co) continue;
            //cout << "ko1" << endl;
            dist7[e.to][(nc+e.co)%7] = nc+e.co;
            if(e.to == n-1) continue;
            q.emplace(nc+e.co, e.to);
        }
    }
    // for(int i = 0; i < n; i++){
    //     cout << "i: " << i << endl;
    //     for(int j = 0; j < 7; j++){
    //         cout << dist7[i][j] << endl;
    //     }
    // }
    int ans = min(dist4[n-1][0], dist7[n-1][0]);
    cout << ans << endl;
    return 0;
}
