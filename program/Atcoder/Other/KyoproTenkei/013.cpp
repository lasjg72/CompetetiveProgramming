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

const int INF = 1001001001;
int n, m;
struct edge{
    int to, co;
    edge(int to, int co): to(to), co(co){};
};

vector<vector<edge>> g;
vector<int> dist1, dist2;

void dfs(int x){
    priority_queue<P, vector<P>, greater<P>> q;
    dist1[x] = 0;
    for(edge e: g[x]){
        if(dist1[e.to] <= e.co) continue;
        dist1[e.to] = e.co;
        q.emplace(e.co, e.to);
    }
    while(!q.empty()){
        int nv = q.top().second;
        int nc = q.top().first;
        q.pop();
        for(edge e : g[nv]){
            if(dist1[e.to] <= e.co+dist1[nv]) continue;
            dist1[e.to] = e.co+dist1[nv];
            q.emplace(dist1[e.to], e.to);
        }
    }
}

void dfs2(int x){
    priority_queue<P, vector<P>, greater<P>> q;
    dist2[x] = 0;
    for(edge e: g[x]){
        if(dist2[e.to] <= e.co) continue;
        dist2[e.to] = e.co;
        q.emplace(e.co, e.to);
    }
    while(!q.empty()){
        int nv = q.top().second;
        int nc = q.top().first;
        q.pop();
        for(edge e : g[nv]){
            if(dist2[e.to] <= e.co+dist2[nv]) continue;
            dist2[e.to] = e.co+dist2[nv];
            q.emplace(dist2[e.to], e.to);
        }
    }
}

int main()
{
    cin >> n >> m;
    g.resize(n);
    dist1.resize(n);
    dist2.resize(n);
    for(int i = 0; i < n; i++){
        dist1[i] = INF;
        dist2[i] = INF;
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    dfs(0);
    dfs2(n-1);
    for(int i = 0; i < n; i++){
        cout << dist1[i] + dist2[i] << endl;
    }
    return 0;
}