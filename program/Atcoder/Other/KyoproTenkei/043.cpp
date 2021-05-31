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
    int a, b, r, c;
    cin >> a >> b >> r >> c;
    a--; b--; r--; c--;
    int INF = 1001001001;
    vector<vector<char>> s(h, vector<char>(w));
    vector<vector<bool>> used(h, vector<bool>(w, false));
    vector<vector<int>> ans(h, vector<int>(w, INF));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> s[i][j];
        }
    }
    
    queue<P> q;
    q.push({a, b});
    used[a][b] = true;
    ans[a][b] = 0;
    int num = 0;
    while(!q.empty()){
        P p = q.front(); q.pop();
        int x[4] = {1, 0, -1, 0};
        int y[4] = {0, 1, 0, -1};
        for(int i = 0; i < 4; i++){
            int nx = p.first+x[i];
            int ny = p.second+y[i];
            while(nx < h && nx >= 0 && ny < w && ny >= 0 && s[nx][ny] == '.'){
                //cout << "nx: " << nx << "ny: " << ny << endl;
                if(p.first == a && p.second == b) {
                    ans[nx][ny] = 0;
                    q.push({nx, ny});
                    nx += x[i];
                    ny += y[i];
                }
                else if(ans[nx][ny] >= ans[p.first][p.second]+1){
                    ans[nx][ny] = ans[p.first][p.second]+1;
                    q.push({nx, ny});
                    nx += x[i];
                    ny += y[i];
                }else break;
            }
        }
    }
    cout << ans[r][c] << endl;
    // for(int i = 0; i < h; i++){
    //     for(int j = 0; j < w; j++){
    //         if(s[i][j] == '#') cout << '#';
    //         else cout << ans[i][j];
    //     }
    //     cout << endl;
    // }
    return 0;
}