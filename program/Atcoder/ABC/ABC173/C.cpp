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
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> c(h, vector<char>(w));
    vector<vector<char>> tmp(h, vector<char>(w));
    for(int i = 0; i< h; i++){
        for(int j = 0; j < w; j++){
            cin >> c[i][j]; 
        }
    }
    int ans = 0;
    int to = 0;
    for(int bith = 0; bith < (1<<h); bith++){
        for(int bitw = 0; bitw < (1<<w); bitw++){
        tmp = c;
        
        for(int i = 0; i < h; i++){

            if(bith & (1 << i)){
                for(int a = 0; a < w; a++){
                    tmp[i][a] = 'r';
                }
            }
        }

            
                for(int j = 0; j < w; j++){
                    if(bitw & (1 << j)){
                        for(int a = 0; a < h; a++){
                            tmp[a][j] = 'r';
                        }
                    }
                    
                }
                int num = 0;
                    for(int l = 0; l< h; l++){
                        for(int b = 0; b < w; b++){
                            
                            //cout << tmp[l][b];
                            if(tmp[l][b] == '#') num++; 
                        }
                    }
                    //cout << endl
                    //cout << "--" << endl;
                    
                    if(num == k) ans++;
            }
    }
    cout << ans << endl;
    return 0;
}