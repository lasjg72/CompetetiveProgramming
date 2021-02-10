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
    int h, w, ch, dh, cw, dw;
    cin >> h >> w >> ch >> cw >> dh >> dw;
    vector<vector<char>> s(h, vector<char>(w));
    vector<vector<int>> value(h, vector<int>(w));

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> s[i][j];
            value[i][j] = -1;
        }
    }
    int vx[4] = {1, 0, -1, 0};
    int vy[4] = {0, 1, 0, -1};

    value[ch-1][cw-1] = 0;

    queue<pair<int, int>> q;
    q.push({ch-1, cw-1});
    //vector<pair<int, int>> kouho;

    while(1){
        vector<pair<int, int>> kouho;
        while(!q.empty()){
            pair<int, int> now = q.front(); q.pop();
            //cout << "now: " << now.first << ", " << now.second << endl;
            bool ok = true, ok2 = false;
            for(int i = 0; i < 4; i++){
                if(now.first + vx[i] >=0 && now.first + vx[i] < h && now.second + vy[i] >= 0 && now.second + vy[i] < w){    
                    if(value[now.first+vx[i]][now.second+vy[i]] == -1 && s[now.first+vx[i]][now.second+vy[i]] == '.'){
                        q.push({now.first+vx[i],now.second+vy[i]});
                        value[now.first+vx[i]][now.second+vy[i]] = value[now.first][now.second];
                        //cout << value[now.first+vx[i]][now.second+vy[i]] << endl;
                        ok = false;
                    }else if(s[now.first+vx[i]][now.second+vy[i]] == '#'){
                        ok2 = true;
                    }
                }
            }
            if(ok){ //これ以上どこにも進めなくなった→ワープ
                if(ok2){
                        kouho.push_back({now.first, now.second});
                        s[now.first][now.second] = '#';
                    // for(int x = -2; x <= 2; x++){
                    //     for(int y = -2; y <= 2; y++){
                    //         if(now.first + x >=now.secondow.first + x < wnow.secondw[1] + y >= 0 && now[1] + y < h && s[now.first+x][now[now.second== '.' && value[now.first+x][now[now.second>= value[now.first][now[now.second             //     }
                    // }
                    }
                }
        }

        //cout << "kouho size: " << kouho.size() << endl;

        if(kouho.empty()) break;
        else{
            for(int i = 0; i < kouho.size(); i++){
                pair<int, int> now = kouho[i];
                for(int x = -2; x <= 2; x++){
                    for(int y = -2; y <= 2; y++){
                        
                        if(x == 0 && y == 0) continue;
                        //cout << "kakunin" << endl;
                        if(now.first + x >=0 && now.first + x < h && now.second + y >= 0 && now.second + y < w && s[now.first+x][now.second+y] == '.'){
                            //cout << "kakunin2" << endl;
                            if(value[now.first+x][now.second+ y] == -1){
                                value[now.first+x][now.second+ y] = value[now.first][now.second] + 1;
                                q.push({now.first+x, now.second+y});
                                s[now.first][now.second] = '#';
                            }else if(value[now.first+x][now.second+ y] > value[now.first][now.second]){
                                value[now.first+x][now.second+ y] = value[now.first][now.second] + 1;
                                q.push({now.first+x, now.second+y});
                                s[now.first][now.second] = '#';
                            }
                        }

                    }
                }
            }
        }

    }
    cout << value[dh-1][dw-1] << endl;
    return 0;
}