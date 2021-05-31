#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(s[i] == s[j]) dp[i][j] = max(dp[i][j], dp[i+1][j+1]+1);
            ans = max(ans, min(dp[i][j], j-i));
        }
    }
    //int r = n-1, l = 0;
    // vector<vector<string>> t(n, vector<string>(n+1, ""));
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         if(i+j > n-1) continue;
    //         t[i][j+1] = t[i][j]+s[i+j];
    //     }
    // }
    // while(r-l>1){
    //     int len = (r+l)/2;
    //     //cout << "len: " << len << endl;
    //     // if(len > n/2){
    //     //     r = len;
    //     //     continue;
    //     // }
    //     bool flag = false;
    //     for(int i = 0; i <= n-2*len; i++){
    //         string now = t[i][len];
    //         for(int j = i+len; j <= n-len; j++){
    //             if(now == t[j][len]) {
    //                 ans = max(ans, len);
    //                 flag = true;
    //             }
    //         }
    //     }
    //     if(flag){
    //         l = len;
    //     }else{
    //         r = len;
    //     }
    // }
    // for(int i = 0; i < n-n/2; i++){
    //     for(int j = 1; j <= n/2; j++){
    //         string now = s.substr(i, j);
    //         for(int k = n-n/2; k < n; k++){
    //             if(now == s.substr(k, j)) ans = max(ans, j);
    //         }
    //     }
    // }
    cout << ans << endl;
    return 0;
}