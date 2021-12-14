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
using P = pair<int, int>;

ll dp[5005][5005];

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<P> ab(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) ab[i] = {a[i], b[i]};
    
    sort(ab.begin(), ab.end());
    dp[0][ab[0].second] = 1;
    dp[0][0] = 1;
    vector<int> tot(5005);
    tot[0] = 1;
    if(ab[0].second <= 5000) tot[ab[0].second] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= 5000; j++){
            // for(int k = 0; k < i; k++){
            //     if(j >= ab[i].second){
            //         dp[i][j] += dp[k][j-ab[i].second];
            //         dp[i][j] %= mod;
            //     }
            // }
            if(j >= ab[i].second){
                dp[i][j] += tot[j-ab[i].second];
                dp[i][j] %= mod;
            }
        } 
        for(int j = 0; j <= 5000; j++){
            tot[j] += dp[i][j];
            tot[j] %= mod;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= ab[i].first; j++){
            //if(dp[i][j] > 0) cout << "dp[" << i << "][" << j << "]: " << dp[i][j] << endl;
            ans += dp[i][j];
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}