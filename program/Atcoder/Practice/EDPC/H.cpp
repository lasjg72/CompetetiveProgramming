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
const int mod = 1e9+7;
ll dp[1005][1005];

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }
    int x[2] = {1, 0};
    int y[2] = {0, 1};
    vector<vector<bool>> used(h, vector<bool>(w, false));
    queue<P> q;
    q.push(P(0, 0));
    dp[0][0] = 1;
    while(!q.empty()){
        P p = q.front(); q.pop();
        for(int i = 0; i < 2; i++){
            int nx = p.first+x[i];
            int ny = p.second+y[i];
            if(nx >= h || nx < 0 || ny >= w || ny < 0) continue;
            if(a[nx][ny] == '#') continue;
            //cout << "nx, ny: " << nx << " " << ny << endl;
            if(!used[nx][ny]){
                q.push(P(nx, ny));
                used[nx][ny] = true;
            }
            dp[nx][ny] += dp[p.first][p.second];
            //cout << dp[nx][ny] << endl;
            dp[nx][ny] %= mod;
        }
    }
    cout << dp[h-1][w-1] << endl;;
    return 0;
}