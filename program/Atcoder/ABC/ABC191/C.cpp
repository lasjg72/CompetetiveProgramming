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
    int h, w;
    cin >> h >> w;
    vector<vector<char>> s(h, vector<char>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> s[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int tmp = 0;
            if(s[i][j] == '#'){
                if(s[i-1][j-1] == '.'){
                    if(s[i-1][j] == s[i][j-1]) ans++;
                }
                if(s[i+1][j+1] == '.'){
                    if(s[i+1][j] == s[i][j+1]) ans++;
                }
                if(s[i+1][j-1] == '.'){
                    if(s[i+1][j] == s[i][j-1]) ans++;
                }
                if(s[i-1][j+1] == '.'){
                    if(s[i-1][j] == s[i][j+1]) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}