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
    vector<vector<int>> L(h, vector<int>(w, 0)), R(h, vector<int>(w, 0)), D(h, vector<int>(w, 0)), U(h, vector<int>(w, 0));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == '#') continue;
            else{
                if(j == 0) L[i][j] = 1;
                else{
                    L[i][j] = L[i][j-1] + 1;
                }
            }
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = w-1; j >= 0; j--){
            if(s[i][j] == '#') continue;
            else{
                if(j == w-1) R[i][j] = 1;
                else{
                    R[i][j] = R[i][j+1] + 1;
                }
            }
        }
    }

    for(int i = h-1; i >= 0; i--){
        for(int j = 0; j < w; j++){
            if(s[i][j] == '#') continue;
            else{
                if(i == h-1) D[i][j] = 1;
                else{
                    D[i][j] = D[i+1][j] + 1;
                }
            }
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == '#') continue;
            else{
                if(i == 0) U[i][j] = 1;
                else{ 
                    U[i][j] = U[i-1][j] + 1;
                }
            }
        }
    }


    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int num = L[i][j] + R[i][j] + D[i][j] + U[i][j]-3;
                // for(int k = 0; k < 4; k++){
                //     int nowx = i, nowy = j;
                //     if(nowx+x[k] < 0 || nowx+x[k] >= h || nowy+y[k] < 0 || nowy+y[k] >= w) {
                //         continue;
                //     }

                //     // while(s[nowx+x[k]][nowy+y[k]] == '.'){
                //     //     num++;
                //     //     nowx = nowx+x[k];
                //     //     nowy = nowy+y[k];
                //     //     if(nowx+x[k] < 0 || nowx+x[k] >= h || nowy+y[k] < 0 || nowy+y[k] >= w) {
                //     //         break;
                //     //     }
                //     // }
                // }
            ans = max(ans, num);
        }
        
    }

    cout << ans << endl;
    return 0;
}