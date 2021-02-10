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
    ll mod = 1e9+7;
    vector<vector<char>> s(h, vector<char>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> s[i][j];
        }
    }
    vector<vector<int>> num(h, vector<int>(w, 0));
    num[0][0] = 1;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int ni = i, nj = j;
            while(ni+1 < h){
                if(s[ni+1][j] == '#') break;
                if(s[ni+1][j] == '.') num[ni+1][j] += num[i][j];
                num[ni+1][j] %= mod;
                ni++;
            }
            ni = i, nj = j;
            while(nj+1 < w){
                if(s[i][nj+1] == '#') break;
                if(s[i][nj+1] == '.') num[i][nj+1] += num[i][j] % mod; //下
                num[i][nj+1] %= mod;
                nj++;
            }
            ni = i, nj = j;
            while(ni+1 < h && nj+1 < w){
                if(s[ni+1][nj+1] == '#') break;
                if(s[ni+1][nj+1] == '.') num[ni+1][nj+1] += num[i][j] %mod; //右下
                num[ni+1][nj+1] %= mod;
                ni++; nj++;
            }
        }
    }
    // for(int i = 0; i < h; i++){
    //     for(int j = 0; j < w; j++){
    //         cout << num[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    num[h-1][w-1] %= mod;
    cout << num[h-1][w-1] << endl;
    return 0;
}