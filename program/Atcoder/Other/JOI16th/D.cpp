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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<vector<int>> sum(m, vector<int>(n+1, 0));
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
        mp[a[i]]++;
        for(int j = 0; j < m; j++){
            if(a[i] == j) sum[a[i]][i+1] = sum[a[i]][i]+1;
            else sum[j][i+1] = sum[j][i];
        }
    }
    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n+1; j++){
    //         cout << sum[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<int> dp(1<<m, 1001001001);
    dp[0] = 0;
    for(int i = 0; i < (1<<m); i++){
        int num = 0;
        for(int j = 0; j < m; j++){
            if(i>>j&1) num += mp[j];
        }
        for(int j = 0; j < m; j++){
            if(~i>>j&1){
                dp[i|(1<<j)] = min(dp[i|(1<<j)], dp[i]+mp[j]-(sum[j][num+mp[j]]-sum[j][num]));
            }
        }
    }
    cout << dp[(1<<m)-1] << endl;
    return 0;
}