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
        for(int j = 0; j < w; j++) cin >> a[i][j];
    }
    bool ok = true;
    for(int i1 = 0; i1 < h; i1++){
        for(int i2 = i1+1; i2 < h; i2++){
            for(int j1 = 0; j1 < w; j1++){
                for(int j2 = j1+1; j2 < w; j2++){
                    if(a[i1][j1] + a[i2][j2] > a[i2][j1]+a[i1][j2]) ok = false;
                }
            }
        }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}