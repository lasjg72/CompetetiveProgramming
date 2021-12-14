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
    for(int i = 0; i < n; i++){
        d[i][i] = 0;
    }
    int ans = 0;
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

                if(d[i][j] < INF) ans += d[i][j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}