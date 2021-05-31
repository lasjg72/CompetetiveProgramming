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

struct E{
    int to;
    int co;
    //E(int to = 0, int co = 0) : to(to), co(co){}
    E(int to, int co){
        this->to = to;
        this->co = co;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<E>> g(n);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].emplace_back(b, c);
    }
    int INF = 1001001001;
    for(int sv = 0; sv < n; sv++){
        vector<int> dist(n, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        for(E e : g[sv]){
            if(dist[e.to] <= e.co) continue;
            dist[e.to] = e.co;
            que.emplace(e.co, e.to);
        }
        while(!que.empty()){
            pair<int, int> p = que.top(); que.pop();
            for(E e : g[p.second]){
                if(dist[e.to] <= p.first+e.co) continue;
                dist[e.to] = p.first+e.co;
                que.emplace(p.first+e.co, e.to);
            }
        }
        int ans = dist[sv];
        if(ans == INF) ans = -1;
        cout << ans << endl;
    }
    return 0;
}