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
const int mod = 1000000007;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> x(q), y(q), z(q);
    vector<ll> W(q);
    for(int i = 0; i < q; i++){
        cin >> x[i] >> y[i] >> z[i] >> W[i];
    }
    vector<int> w(100);
    ll ans = 1;
    for(int i = 0; i < 60; i++){
        for(int j = 0; j < q; j++){
            w[j] = (W[j] / (1LL<<i))%2LL;
        }
        ll num = 0;
        for(int bit = 0; bit < (1<<n); bit++){
            ll bi[15];
            for(int j = 0; j < n; j++){
                bi[j] = (bit / (1<<j))%2;
            }
            bool flg = true;
            for(int j = 0; j < q; j++){
                if((bi[x[j]-1] | bi[y[j]-1] | bi[z[j]-1]) != w[j]) flg = false;
            }
            if(flg == true) num++;
        }
        ans = (ans*num)%mod;
    }
    cout << ans << endl;
    return 0;
}