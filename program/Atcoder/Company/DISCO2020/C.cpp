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
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> s(h, vector<char>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> s[i][j];
        }
    }
    vector<vector<int>> ans(h, vector<int>(w));
    int now = 1;
    bool flag1 = false;
    for(int i = 0; i < h; i++){
        bool flag = false;
        if(flag1){
            flag1 = false;
        }
        for(int j = 0; j < w; j++){
            if(s[i][j] == '#'){
                flag1 = true;
                if(flag){
                    now++;
                }else{
                    flag = true;
                }
            }
            ans[i][j] = now;
        }
    }
    return 0;
}