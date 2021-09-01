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
    int N;
    cin >> N;
    vector<int> a(N);
    int tot = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        tot += a[i];
    }
    int l = 0, r = 100005;
    int ans = 1001001001;
    //cout << "tot: " << tot << endl;
    while(r-l>1){
        int mid = (l+r)/2;
        // cout << "mid: " << mid << endl;
        // cout << "l: " << l << " r: " << r << endl;
        // 二次元配列
        vector<vector<bool>> dp(N + 1, vector<bool>(mid + 1, false));
        // 初期化
        for (int i = 0; i <= N; i++) {
            dp[i][0] = true;
        }
        // 更新
        for (int i = 0; i < N; i++) {
            for (int k = 0; k <= mid; k++) {
                if (k - a[i] >= 0) dp[i + 1][k] = dp[i + 1][k] | dp[i][k - a[i]];
                dp[i + 1][k] = dp[i + 1][k] | dp[i][k];
            }
        }
        if (dp[N][mid]) {
            //cout << "true" << endl;
            ans = min(ans, max(mid, tot-mid));
            if(tot-mid > mid){
                l = mid;
            }else{
                r = mid;
            }
        } else {
            //cout << "false" << endl;
            for(int i = mid; i >= 0; i--){
                if(dp[N][i]){
                    if(tot-i <= mid){
                        r = mid;
                        break;
                    }else{
                        l = mid;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}