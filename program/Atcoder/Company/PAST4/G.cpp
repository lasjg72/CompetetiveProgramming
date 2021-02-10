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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> maze(n, vector<char>(m));
    vector<vector<int>> mark(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> maze[i][j];
            if(maze[i][j] == '.'){
                mark[i][j] = 0;
            }else if(maze[i][j] == '#'){
                mark[i][j] = -1;
            }
        }
    }

    int x[] = {1, 0, -1, 0};
    int y[] = {0, -1, 0, 1};
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            for(int a = 0; a < n; a++){
                for(int b = 0; b < m; b++){
                    if(maze[a][b] == '.'){
                        mark[a][b] = 0;
                    }else if(maze[a][b] == '#'){
                        mark[a][b] = -1;
                    }
                }
            }

            char now = maze[i][j];
            if(now == '#'){
                mark[i][j] = 1;
                queue<pair<int, int>> q;
                q.push({i, j});
                while(!q.empty()){
                    pair<int, int> p = q.front();
                    q.pop();
                    for(int k = 0; k < 4; k++){
                        if(p.first + x[k] >= n || p.first + x[k] < 0 || p.second + y[k] >= m || p.second + y[k] < 0) continue;
                        if(maze[p.first+x[k]][p.second+y[k]] == '.' && mark[p.first+x[k]][p.second+y[k]] == 0){
                            q.push({p.first + x[k], p.second + y[k]});
                            mark[p.first+x[k]][p.second + y[k]] = 1;
                        }
                    }
                }
                bool flag = true;
                for(int k = 0; k < n; k++){
                    for(int l = 0; l < m; l++){
                        if(mark[k][l] == 0) flag = false;
                    }
                }
                if(flag){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}