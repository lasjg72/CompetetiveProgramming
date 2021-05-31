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
    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < t.size(); j++){
            if(s[i] == t[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            }else{
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    int num = dp[s.size()][t.size()];
    //cout << num << endl;
    string ans(num, ' ');
    int len = num;
    int slen = s.size();
    int tlen = t.size();
    while(len > 0){
        if(s[slen-1] == t[tlen-1]){
            ans[len-1] = s[slen-1];
            //cout << "ans: " << ans[len-1] << endl;
            len--;
            slen--;
            tlen--;
            //cout << "1" << endl;
        }else if(dp[slen][tlen] == dp[slen-1][tlen]){
            slen--;
            //cout << "2" << endl;
        }else{
            tlen--;
            //cout << "3" << endl;
        }
    }
    cout << ans << endl;
    return 0;
}