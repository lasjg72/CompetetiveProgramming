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

//using edge = struct {int to; ll cost;};
struct edge{
    int to;
    ll cost;
    edge(int to, ll cost) : to(to), cost(cost){}
};

const int INF = 1001001001;
vector<edge> tree[100005];
vector<bool> mark(100005);
vector<ll> d(100005);
int k;


void dfs(int s, ll c){
    d[s] = c;
    for(edge& t: tree[s]){
        if(mark[t.to]) continue;
        else{
            mark[t.to] = true;
            //cout << "s: " << s << "t: " << t.to << "cost: " << c+t.cost << endl; 
            dfs(t.to, c+t.cost);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        tree[a].emplace_back(b,c);
        tree[b].emplace_back(a, c);
    }
    // for(auto e: tree[0]){
    //     cout << "to: " << e.to << " : " << e.cost << endl;
    // }
    int q;
    cin >> q >> k;
    k--;
    mark[k] = true;
    dfs(k, 0);
    while(q--){
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << d[x] + d[y] << endl;
    }
    return 0;
}