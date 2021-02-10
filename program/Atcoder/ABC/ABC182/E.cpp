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

int main()
{
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<vector<char>> maze(h, vector<char>(w, '.'));
    vector<vector<int>> mark(h, vector<int>(w, 0));
    vector<int> c(n), d(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        c[i] = a; d[i] = b;
        maze[a][b] = 'd';
        mark[a][b] = 1;
        ans++;
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        maze[a][b] = '#';
    }
    int x[] = {0, 1, 0, -1};
    int y[] = {1, 0, -1, 0};
    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < 4; j++){
            int nx = c[i] + x[j];
            int ny = d[i] + y[j];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(maze[nx][ny] == '#') continue;
            while(maze[nx][ny] == '.'){
                if(mark[nx][ny] != 1) ans++;
                mark[nx][ny] = 1;
                nx += x[j];
                ny += y[j];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) break;
            }
        }
    }
    // for(int i = 0; i < h; i++){
    //     for(int j = 0; j < w; j++){
    //         cout << mark[i][j];
    //     }
    //     cout << endl;
    // }
    cout << ans << endl;
    return 0;
}