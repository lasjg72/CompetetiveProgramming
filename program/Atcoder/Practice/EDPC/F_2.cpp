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

int dp[3005][3005];

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i] == t[j]) dp[i+1][j+1] = dp[i][j]+1;
            else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }
    int llen = n;
    int rlen = m;
    string ans = "";
    while(llen > 0 || rlen > 0){
        int now = dp[llen][rlen];
        if(llen-1 >= 0 && now == dp[llen-1][rlen]){
            llen--;
        }else if(rlen-1 >= 0 && now == dp[llen][rlen-1]){
            rlen--;
        }else{
            llen--;
            rlen--;
            ans += s[llen];
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}