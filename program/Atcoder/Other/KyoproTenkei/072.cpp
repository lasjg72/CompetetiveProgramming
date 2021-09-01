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

vector<vector<char>> c;
vector<vector<bool>> used;
int x[] = {1, 0, -1, 0};
int y[] = {0, -1, 0, 1};

int h, w;

int dfs(int sx, int sy, int a, int b){
    if(sx == a && sy == b && used[a][b] == true) return 0;

    used[a][b] = true;

    int res = -10000;
    for(int i = 0; i < 4; i++){
        int nx = a + x[i];
        int ny = b + y[i];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w || c[nx][ny] == '#') continue;
        if((nx != sx || ny != sy) && used[nx][ny] == true) continue;
        int v = dfs(sx, sy, nx, ny);
        res = max(res, v+1);
    }

    used[a][b] = false;
    //cout << "res: " << res << endl;
    return res;
}

int main()
{
    cin >> h >> w;
    c.resize(h);
    used.resize(h);
    for(int i = 0; i < h; i++){
        c[i].resize(w);
        used[i].resize(w, false);
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> c[i][j];
        }
    }
    int ans = -1;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            ans = max(ans, dfs(i, j, i, j));
        }
    }
    if(ans <= 2) ans = -1;
    cout << ans << endl;
    return 0;
}