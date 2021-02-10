#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

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
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == '#'){
                if(i != 0 && s[i-1][j] == '#') continue;
                if(j != 0 && s[i][j-1] == '#') continue;
                if(i != h-1 && s[i+1][j] == '#') continue;
                if(j != w-1 && s[i][j+1] == '#') continue;
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}