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
    int ans = 0;
    for(int bit = 0; bit < (1<<h); bit++){
        vector<vector<int>> b = a;
        for(int i = 0; i < h; i++){
            if(bit&(1<<i)){
                for(int j = 0; j < w; j++){
                    b[i][j] = (b[i][j]+1)%2;
                }
            }
        }
        int tmp = 0;
        for(int i = 0; i < w; i++){
            int num0 = 0, num1 = 0;
            for(int j = 0; j < h; j++){
                if(b[j][i]) num1++;
                else num0++;
            }
            tmp += max(num0, num1);
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}