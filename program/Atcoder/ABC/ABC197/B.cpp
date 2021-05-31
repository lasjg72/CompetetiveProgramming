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
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    vector<vector<char>> s(h, vector<char>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> s[i][j];
        }
    }
    x--; y--;
    if(s[x][y] == '#'){
        cout << 0 << endl;
        return 0;
    }
    int ans = 1;
    for(int i = 1; i < h; i++){
        if(x+i > h-1) continue;
        if(s[x+i][y] == '.') ans++;
        else break;
    }
    for(int i = 1; i < h; i++){
        if(x-i < 0) continue;
        if(s[x-i][y] == '.') ans++;
        else break;
    }
    for(int i = 1; i < w; i++){
        if(y+i > w-1) continue;
        if(s[x][y+i] == '.') ans++;
        else break;
    }
    for(int i = 1; i < w; i++){
        if(y-i < 0) continue;
        if(s[x][y-i] == '.') ans++;
        else break;
    }
    cout << ans << endl;
    return 0;
}