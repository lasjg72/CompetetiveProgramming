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

struct edge{
    int to;
    int cost;
    edge(int to, int cost):to(to), cost(cost){};
};

int main()
{
    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<edge>> g(n);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
    }
    
    return 0;
}