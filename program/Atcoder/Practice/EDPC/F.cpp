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
using ll = long long;\
int dp[3005][3005];

int main()
{
    string s, t;
    cin >> s >> t;
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < t.size(); j++){
            if(s[i] == t[j]) dp[i+1][j+1] = dp[i][j]+1;
            else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    //cout << dp[s.size()][t.size()] << endl;
    int slen = s.size();
    int tlen = t.size();
    string ans;
    while(slen != 0 && tlen != 0){
        if(dp[slen][tlen] == dp[slen-1][tlen]) slen--;
        else if(dp[slen][tlen] == dp[slen][tlen-1]) tlen--;
        else{
            ans += s[slen-1];
            slen--;
            tlen--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
