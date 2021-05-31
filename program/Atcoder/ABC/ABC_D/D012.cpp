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

const ll INF = 1001001001001001001;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    for(int i = 0; i < m; i++){
        int a, b;
        ll t;
        cin >> a >> b >> t;
        a--; b--;
        dist[a][b] = t;
        dist[b][a] = t;
    }
    for(int i = 0; i < n; i++){
        dist[i][i] = 0;
    }
    for(int k = 0; k < n; k++){
        for(int j = 0; j < n; j++){
            for(int i = 0; i < n; i++){
                if(dist[i][k] == INF || dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for(int i = 0; i < n; i++){
        ll mx = 0;
        for(int j = 0; j < n; j++){

            mx = max(mx, dist[i][j]);
        }
        //cout << "mx: " << mx << endl;
        q.push(mx);
    }
    ll ans = q.top();
    cout << ans << endl;
    return 0;
}