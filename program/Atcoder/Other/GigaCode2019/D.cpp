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
    ll k, v;
    cin >> h >> w >> k >> v;
    vector<vector<ll>> a(h, vector<ll>(w));
    vector<vector<ll>> sum(h+1, vector<ll>(w+1, 0));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
            //sum[i+1][j+1] = a[i][j];
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            sum[i+1][j+1] = sum[i][j+1]+sum[i+1][j]-sum[i][j]+a[i][j];
        }
    }
    int ans = 0;
    for(int x1 = 0; x1 < h; x1++){
        for(int y1 = 0; y1 < w; y1++){
            for(int x2 = x1+1; x2 < h+1; x2++){
                for(int y2 = y1+1; y2 < w+1; y2++){
                    ll now = sum[x2][y2]-sum[x2][y1]-sum[x1][y2]+sum[x1][y1];
                    if(v >= now + (ll)(x2-x1)*(ll)(y2-y1)*k) {
                        ans = max(ans, (x2-x1)*(y2-y1));
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}