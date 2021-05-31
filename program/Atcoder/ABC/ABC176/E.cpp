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
using P = pair<int, int>;

int main()
{
    int H, W, m;
    cin >> H >> W >> m;
    set<P> s;
    vector<int> h(m), w(m), mh(H, 0), mw(W, 0);
    for(int i = 0; i < m; i++){
        cin >> h[i] >> w[i];
        h[i]--; w[i]--;
        mh[h[i]]++;
        mw[w[i]]++;
        s.emplace(h[i], w[i]);
    }
    // 各軸の最大値を計算
    int mxh = 0, mxw = 0;
    for(int i = 0; i < m; i++){
        mxh = max(mxh, mh[h[i]]);
        mxw = max(mxw, mw[w[i]]);
    }
    // 最大値を持つ点を各軸ごとにリストアップ
    vector<int> hp, wp;
    for(int i = 0; i < H; i++){
        if(mh[i] == mxh) hp.push_back(i);
    }
    for(int i = 0; i < W; i++){
        if(mw[i] == mxw) wp.push_back(i);
    }
    int ans = mxh+mxw;
    for(int i : hp){
        for(int j : wp){
            //cout << "i: " << i << " j: " << j << endl;
            if(s.count({i, j})) continue;
            cout << ans << endl;
            return 0;
        }
    }
    cout << ans-1 << endl;
    return 0;
}