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

ll modpow(int x, int n){
    if(n == 0) return 1;
    else if(n%2 == 0) return (modpow(x, n/2)*modpow(x, n/2))%mod;
    else return (modpow(x, n-1)*x)%mod;
}

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> c(h, vector<char>(w));
    vector<map<char, ll>> mp(1000);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> c[i][j];
            mp[i+j][c[i][j]]++;
        }
    }
    // 対角線の数
    int num = (h-1)+(w-1)+1;
    ll ans = 1;
    for(int i = 0; i < num; i++){
        if(mp[i]['R'] > 0 && mp[i]['B'] > 0){
            cout << 0 << endl;
            return 0;
        }else if(mp[i]['R'] > 0 || mp[i]['B'] > 0){
            // .を全てRに
        }else{
            ans = (ans*2)%mod;
        }
    }
    cout << ans << endl;
    return 0;
}