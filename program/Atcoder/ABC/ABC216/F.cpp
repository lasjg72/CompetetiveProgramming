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

ll dp[5005][5005];

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++){
        if(a[i] >= b[i]) dp[a[i]-b[i]][a[i]] += 1;
        for(int j = 0; j <= 5000; j++){
            if(a[i] >= b[i] && a[i] >= a[j]){
                dp[i][a[i]] += dp[j][a[j]];
                dp[i][a[i]] %= mod;
            }else if(a[i] >= a[j] && ){

            }
        }
    }
    return 0;
}