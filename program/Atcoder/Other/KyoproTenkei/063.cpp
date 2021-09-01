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
    vector<vector<int>> p(h, vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> p[i][j];
        }
    }
    int ans = 0;
    for(int bit = 1; bit < (1<<h); bit++){
        int pos = -1;
        vector<int> num(h*w+1, 0);
        for(int j = 0; j < w; j++){
            bool ok = true;
            int now = -1, hnum = 0;
            for(int i = 0; i < h; i++){
                if(bit>>i&1){
                    hnum++;
                    pos = i;
                    if(now < 0){
                        now = p[i][j];
                    }else if(now != p[i][j]){
                        ok = false;
                        break;
                    }
                }
            }
            if(ok) num[now] += hnum;
        }

        if(pos >= 0){
            for(int i = 0; i < w; i++){
                ans = max(ans, num[p[pos][i]]);
            }
            //if(ans == 5) cout << bit << endl;
        }
    }
    cout << ans << endl;
    return 0;
}