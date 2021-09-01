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
const int mod = 998244353;

int main()
{
    int n, K;
    cin >> n >> K;
    vector<vector<bool>> ok(K, vector<bool>(n, false));
    vector<bool> pos(n, false);
    for(int i = 0; i < K; i++){
        char c;
        int k;
        cin >> c >> k;
        pos[k-1] = true;
        if(c == 'L'){
            for(int j = n-1; j >= k-1; j--) ok[i][j] = true;
        }else{
            for(int j = 0; j < k; j++) ok[i][j] = true;
        }
    }
    ll ans = 1;
    for(int i = 0; i < n; i++){
        ll num = 0;
        for(int j = 0; j < K; j++){
            // cout << "-----" << endl;
            // cout << "j: " << j << " i: " << i << endl;
            // cout << "ok[j][i]: " << ok[j][i] << endl;
            if(ok[j][i]){
                num++;
            }
            // cout << "num: " << num << endl;
        }
        if(pos[i]) num = 1;
        ans *= num;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
