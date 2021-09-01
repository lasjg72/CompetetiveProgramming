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
int dp[1005][1005];

int main()
{
    int q;
    cin >> q;
    while(q--){
        string s, t;
        cin >> s >> t;
        for(int i = 0; i <= s.size(); i++){
            for(int j = 0; j <= t.size(); j++){
                dp[i][j] = 0;
            }
        }
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < t.size(); j++){
                if(s[i] == t[j]) dp[i+1][j+1] = dp[i][j]+1;
                else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        cout << dp[s.size()][t.size()] << endl;
    }
    return 0;
}