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
const ll INF = 1e10;

struct edge{ll to, cost;};
typedef pair<ll,ll> P;
struct graph{
  ll V;
  vector<vector<edge> > G;
  vector<ll> d;

  graph(ll n){
    init(n);
  }

  void init(ll n){
    V = n;
    G.resize(V);
    d.resize(V);
    for(int i = 0; i < V; i++){
      d[i] = INF;
    }
  }

  void add_edge(ll s, ll t, ll cost){
    edge e;
    e.to = t, e.cost = cost;
    G[s].push_back(e);
  }

  void dijkstra(ll s){
    for(int i = 0; i < V; i++){
      d[i] = INF;
    }
    d[s] = 0;
    priority_queue<P,vector<P>, greater<P> > que;
    que.push(P(0,s));
    while(!que.empty()){
      P p = que.top(); que.pop();
      ll v = p.second;
      if(d[v]<p.first) continue;
      for(auto e : G[v]){
        if(d[e.to]>d[v]+e.cost){
          d[e.to] = d[v]+e.cost;
          que.push(P(d[e.to],e.to));
        }
      }
    }
  }
};

int main()
{
    int n, m;
    cin >> n >> m;
    int xab, xac, xbc;
    cin >> xab >> xac >> xbc;
    string s;
    cin >> s;
    graph g(n);
    bool f1 = false, f2 = false;
    for(int i = 0; i < n; i++){
        if(f1 && f2) break;
        if(s[i] == 'A'){
            f1 = true;
            for(int j = i+1; j < n; j++){
                if(s[j] == 'B'){
                    g.add_edge(i, j, xab);
                }else if(s[j] == 'C'){
                    g.add_edge(i, j, xac);
                }
            }
        }else if(s[i] == 'B'){
            f2 = true;
            for(int j = i+1; j< n; j++){
                if(s[j] == 'C'){
                    g.add_edge(i, j, xbc);
                }
            }
        }
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g.add_edge(a, b, c);
    }
    g.dijkstra(0);
    ll ans = g.d[n-1];
    cout << ans << endl;
    return 0;
}