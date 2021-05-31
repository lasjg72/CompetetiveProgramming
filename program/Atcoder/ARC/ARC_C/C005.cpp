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

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> c(h, vector<char>(w));
    int sx, sy, tx, ty;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> c[i][j];
            if(c[i][j] == 's'){
                sx = i; sy = j;
            }else if(c[i][j] == 'g'){
                tx = i; ty = j;
            }
        }
    }
    const int INF = 1001001001;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    queue<P> q;
    q.emplace(sx, sy);
    dist[sx][sy] = 0;
    int x[] = {1, 0, -1, 0};
    int y[] = {0, 1, 0, -1};
    while(!q.empty()){
        int nx = q.front().first; 
        int ny = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int tox = nx + x[i];
            int toy = ny + y[i];
            if(tox < 0 || tox >= h || toy < 0 || toy >= w) continue;
            if(c[tox][toy] == '#'){
                if(dist[tox][toy] > dist[nx][ny]+1){
                    
                    dist[tox][toy] = dist[nx][ny] + 1;
                    q.emplace(tox, toy);
                }
            }else{
                if(dist[tox][toy] > dist[nx][ny]){
                    dist[tox][toy] = dist[nx][ny];
                    q.emplace(tox, toy);
                }
            }
        }
    }
    
    // for(int i = 0; i < h; i++){
    //     for(int j = 0; j < w; j++){
    //         cout << dist[i][j];
    //     }
    //     cout << endl;
    // }

    if(dist[tx][ty] <= 2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}