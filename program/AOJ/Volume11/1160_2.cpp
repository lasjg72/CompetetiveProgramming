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

bool used[55][55];
char c[55][55];

void dfs(int a, int b){
    used[a][b] = true;
    int x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    for(int i = 0; i < 8; i++){
        int nx = a+x[i];
        int ny = b+y[i];
        if(!used[nx][ny] && c[nx][ny] == '1'){
            dfs(nx, ny);
        }
    }
}

int main()
{
    while(1){
        int w, h;
        cin >> w >> h;
        if(w == 0 && h == 0) return 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> c[i][j];
                used[i][j] = false;
            }
        }
        int ans = 0;
        
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(used[i][j] || c[i][j] != '1') continue;
                ans++;
                dfs(i, j);
            }
        }
        cout << ans << endl;
    }
    return 0;
}