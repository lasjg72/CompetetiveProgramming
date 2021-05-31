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

ll dp[3005][3005];

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int k = 1; k <= n; k++){
        for(int i = 0; i+k <= n; i++){
            int j = i+k;
            if((n-k)%2==0){
                dp[i][j] = max(dp[i+1][j]+a[i], dp[i][j-1]+a[j-1]);
            }else{
                dp[i][j] = min(dp[i+1][j]-a[i], dp[i][j-1]-a[j-1]);
            }
            //cout << "i: " << i << "j: " << j << endl;
            //cout << dp[i][j] << endl;
        }
    }
    cout << dp[0][n] << endl;
    return 0;
}