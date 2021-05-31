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
    int INF = 1001001001;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }
    vector<vector<int>> b(h, vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(a[i][j] == '+') b[i][j] = 1;
            else b[i][j] = -1;
        }
    }
    vector<vector<int>> f(h, vector<int>(w, -INF));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if((i+j)%2 == 0) f[i][j] = INF;
        }
    }
    
    for(int i = h-1; i >= 0; i--){
        for(int j = w-1; j >= 0; j--){
            if(i == h-1 && j == w-1) f[i][j] = 0;
            else{
                if((i+j)%2 == 0){
                    if(i+1 < h && j+1 < w) f[i][j] = max(f[i+1][j]+b[i+1][j], f[i][j+1]+b[i][j+1]);
                    else if(i+1 < h) f[i][j] = f[i+1][j]+b[i+1][j];
                    else if(j+1 < w) f[i][j] = f[i][j+1]+b[i][j+1];
                }else{
                    if(i+1 < h && j+1 < w) f[i][j] = min(f[i+1][j]-b[i+1][j], f[i][j+1]-b[i][j+1]);
                    else if(i+1 < h) f[i][j] = f[i+1][j]-b[i+1][j];
                    else if(j+1 < w) f[i][j] = f[i][j+1]-b[i][j+1];
                }
            }
        }
    }
    //cout << f[0][0] << endl;
    if(f[0][0] == 0) cout << "Draw" << endl;
    else if(f[0][0] > 0) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    return 0;
}