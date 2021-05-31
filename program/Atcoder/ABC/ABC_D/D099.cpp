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
    int n, C;
    cin >> n >> C;
    vector<vector<int>> d(C, vector<int>(C));
    for(int i = 0; i < C; i++){
        for(int j = 0; j < C; j++){
            cin >> d[i][j];
        }
    }
    vector<vector<int>> c(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> c[i][j];
            c[i][j]--;
        }
    }
    vector<vector<int>> sum(3, vector<int>(C, 0));
    for(int c1 = 0; c1 < C; c1++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sum[(i+j)%3][c1] += d[c[i][j]][c1];
            }
        }
    }
    int ans = 1001001001;
    for(int c1 = 0; c1 < C; c1++){
        for(int c2 = 0; c2 < C; c2++){
            if(c1 == c2) continue;
            for(int c3 = 0; c3 < C; c3++){
                if(c1 == c3 || c2 == c3) continue;
                int nc[3] = {c1, c2, c3};
                int now = 0;
                for(int i = 0; i < 3; i++){
                    now += sum[i][nc[i]];
                }
                ans = min(ans, now);
            }
        }
    }
    cout << ans << endl;
    return 0;
}