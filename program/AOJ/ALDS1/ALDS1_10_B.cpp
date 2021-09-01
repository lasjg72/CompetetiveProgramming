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

const ll INF = 1001001001001001001;
ll dp[105][105];

int main()
{
    int n;
    cin >> n;
    vector<ll> p(n+1);
    for(int i = 0; i < n; i++){
        cin >> p[i] >> p[i+1];
    }
    for(int j = 2; j < n+1; j++){
        for(int i = 0; i < n-j+1; i++){
            dp[i][i+j-1] = INF;
            for(int k = i; k < i+j-1; k++){
                dp[i][i+j-1] = min(dp[i][i+j-1], dp[i][k]+dp[k+1][i+j-1]+p[i]*p[k+1]*p[i+j]);
            }
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}