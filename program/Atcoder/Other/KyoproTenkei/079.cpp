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
    vector<vector<int>> b(h, vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> b[i][j];
        }
    }
    ll ans = 0;
    for(int i = 0; i < h-1; i++){
        for(int j = 0; j < w-1; j++){
            if(a[i][j] < b[i][j]){
                int now = b[i][j]-a[i][j];
                b[i][j] -= now;
                b[i+1][j] -= now;
                b[i][j+1] -= now;
                b[i+1][j+1] -= now;
                ans += now;
            }else if(a[i][j] > b[i][j]){
                int now = a[i][j]-b[i][j];
                b[i][j] += now;
                b[i+1][j] += now;
                b[i][j+1] += now;
                b[i+1][j+1] += now;
                ans += now;
            }
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(a[i][j] != b[i][j]){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    cout << ans << endl;
    return 0;
}
