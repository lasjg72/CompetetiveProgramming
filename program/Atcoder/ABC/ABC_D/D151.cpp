#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;
const int INF = 1001001001;

int main()
{
    int h, w;
    cin >> h >> w;
    char maze[h][w];

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> maze[i][j];
        }
    }

    
    

    int x[4] = {1, 0, -1, 0};
    int y[4] = {0, 1, 0, -1};

    int ans = 0;

    for (int i = 0; i <h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if(maze[i][j] == '#') continue;
            queue<pair<int, int>> que;
            vector<vector<int>> dist(h, vector<int>(w, INF));
            que.push({i, j});
            dist[i][j] = 0;
            while (!que.empty())
            {
                pair<int, int> now = que.front();
                que.pop();
                int f = now.first;
                int s = now.second;
                for(int k = 0; k< 4; k++){
                    if(f+x[k] < 0 || f+x[k] >= h || s+y[k] < 0 || s+y[k] >= w) continue;
                    if(maze[f+x[k]][s+y[k]]=='#') continue;
                    if(dist[f+x[k]][s+y[k]] != INF) continue;
                    dist[f+x[k]][s+y[k]] = dist[f][s]+1;
                    que.push({f+x[k], s+y[k]});
                }
            }
            for(int a = 0; a < h; a++){
                for(int b = 0; b < w; b++){
                    if(dist[a][b] == INF) continue;
                    ans = max(ans, dist[a][b]);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}