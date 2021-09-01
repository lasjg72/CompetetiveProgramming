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
const int INF = 1001001001;

struct edge{
    int to;
    int cost;
    edge(int to, int cost): to(to), cost(cost){};
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<vector<int>> d(n, vector<int>(n, INF));
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back(b);
        d[a][b] = c;
    }
    ll ans = 0;
    return 0;
}