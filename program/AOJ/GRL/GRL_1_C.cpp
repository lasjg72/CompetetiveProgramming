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

struct Edge{
    int to;
    int co;
    Edge(int to, int co):to(to), co(co){}
};

const ll INF = 1001001001001001001;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    for(int i = 0; i < m; i++){
        ll s, t, d;
        cin >> s >> t >> d;
        dist[s][t] = d;
    }
    for(int i = 0; i < n; i++){
        dist[i][i] = 0;
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k] == INF || dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(dist[i][i] < 0){
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dist[i][j] == INF) cout << "INF";
            else cout << dist[i][j];

            if(j != (n-1)) cout << " ";
        }
        cout << endl;
    }
    return 0;
}