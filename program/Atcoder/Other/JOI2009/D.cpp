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

vector<vector<int>> g;
vector<vector<bool>> used, finish;
int tox[4] = {0, 1, 0, -1};
int toy[4] = {1, 0, -1, 0};
int ans, num;
int n, m;

void dfs(int x, int y, int num){
    finish[x][y] = true;
    
    if(g[x][y] == 1 && !used[x][y]){
        num++;

        used[x][y] = true;
        for(int i = 0; i < 4; i++){
            int nx = x+tox[i];
            int ny = y+toy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m) dfs(nx, ny, num);
        }
        used[x][y] = false;
        ans = max(ans, num);
    }else{
       ans = max(ans, num);
       return ; 
    }
    return;
}

int main()
{
    
    cin >> m >> n;
    g.resize(n);
    used.resize(n);
    finish.resize(n);
    for(int i = 0; i < n; i++){
        g[i].resize(m);
        used[i].resize(m);
        finish[i].resize(m);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == 1) {
                num = 0;
                dfs(i, j, 0);
            }
        }
    }
    cout << ans << endl;
    return 0;
}