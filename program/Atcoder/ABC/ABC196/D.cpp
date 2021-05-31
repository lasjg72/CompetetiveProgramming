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

int h, w;
bool used[16][16];
ll ans;

void dfs(int i, int j, int a, int b){
    if(j == w){
        dfs(i+1, 0, a, b);
        // j = 0;
        // i++;
    }
    if(a < 0 || b < 0) return;
    if(i == h){
        //if(a == 0 && b == 0) 
        ans++;
        return ;
    }
    if(used[i][j]) {
        dfs(i, j+1, a, b);
        return ;
    }
    used[i][j] = true;
    dfs(i, j+1, a, b-1);
    if(j+1 < w && !used[i][j+1]){
        used[i][j+1] = true;
        dfs(i, j+1, a-1, b);
        used[i][j+1] = false;
    }
    if(i+1 < h && !used[i+1][j]){
        used[i+1][j] = true;
        dfs(i, j+1, a-1, b);
        used[i+1][j] = false;
    }
    used[i][j] = false;
}

int main()
{
    int a, b;
    cin >> h >> w >> a >> b;

    dfs(0, 0, a, b);
    cout << ans << endl;
    return 0;
}