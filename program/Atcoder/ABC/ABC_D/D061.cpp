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
using P = pair<ll, ll>;
const ll INF = 1LL << 50;

struct edge {
    ll from;
    ll to;
    ll cost;
    //edge(ll to, ll from, ll cost) : to(to), from(from), cost(cost){}
};

int main()
{
    ll n, m;
    cin >> n >> m;
    //vector<vector<P>> g[n];
    vector<edge> e(m);
    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        //g[a].emplace_back(b, c);
        e[i].from = a;
        e[i].to = b;
        e[i].cost = -c;
    }
    vector<ll> d(n, INF);
    d[0] = 0;
    ll num = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            edge now = e[j];
            if(d[now.from] != INF && d[now.to] > d[now.from] + now.cost){
                d[now.to] = d[now.from] + now.cost; 
            }
        }
    }
    ll ans = d[n-1];
    vector<bool> update(n, false);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            edge now = e[j];
            if(d[now.from] != INF && d[now.to] > d[now.from] + now.cost){
                d[now.to] = d[now.from] + now.cost;
                update[now.to] = true;
            }
            if(update[now.from] == true) update[now.to] = true;
        }
    }
    if(update[n-1]) cout << "inf" << endl;
    else cout << -ans << endl;
    return 0;
}