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
int dp[100005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++){
        dp[i] = 1001001001;
    }
    dp[0] = 0;
    for(int i = 0; i <= n; i++){
        if(i+1 <= n) dp[i+1] = min(dp[i+1], dp[i]+1);
        //cout << "dp[i+1]: " << dp[i+1] << endl;
        for(int j = 0; j < 6; j++){
            if(i+(int)pow(6, j+1) <= n)
            dp[i+(int)pow(6, j+1)] = min(dp[i+(int)pow(6, j+1)], dp[i]+1);
            //cout << "dp[i+(int)pow(6, j+1)]: " << dp[i+(int)pow(6, j+1)] << endl;
        }
        for(int j = 0; j < 5; j++){
            if(i+(int)pow(9, j+1) <= n)
            dp[i+(int)pow(9, j+1)] = min(dp[i+(int)pow(9, j+1)], dp[i]+1);
            //cout << "dp[i+(int)pow(9, j+1)]: " << dp[i+(int)pow(9, j+1)] << endl;
        }
    }
    cout << dp[n] << endl;
    return 0;
}