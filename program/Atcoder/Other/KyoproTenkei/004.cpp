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
    vector<vector<int>> a(h, vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }
    vector<vector<int>> sh(h, vector<int>(w, 0));
    vector<vector<int>> sw(h, vector<int>(w, 0));
    for(int i = 0; i < h; i++){
        int tot = 0;
        for(int j = 0; j < w; j++){
                tot += a[i][j];
        }
        for(int j = 0; j < w; j++){
            sh[i][j] = tot;
        }
    }
    for(int i = 0; i < w; i++){
        int tot = 0;
        for(int j = 0; j < h; j++){
            tot += a[j][i];
        }
        for(int j = 0; j < h; j++){
            sw[j][i] = tot;
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << sh[i][j] + sw[i][j] - a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}