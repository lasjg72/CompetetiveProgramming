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
vector<vector<int>> c;
int x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
vector<vector<bool>> used;
int h, w;

void dfs(int a, int b){
    used[a][b] = true;
    for(int i = 0; i < 8; i++){
        int na = a + x[i];
        int nb = b + y[i];
        if(na < 0 || nb < 0 || na >= h || nb >= w) continue;
        if(c[na][nb] == 0) continue;
        if(used[na][nb]) continue;
        dfs(na, nb);
    }
}

int main()
{
    while(1){
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        c.resize(h);
        used.resize(h);
        for(int i = 0; i < h; i++){
            c[i].resize(w);
            used[i].resize(w);
        }
        
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> c[i][j];
                used[i][j] = false;
            }
        }
       
        int ans = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(used[i][j] || c[i][j] == 0) continue;
                else ans++;
                dfs(i, j);
            }
        }
        cout << ans << endl;
    }
    return 0;
}