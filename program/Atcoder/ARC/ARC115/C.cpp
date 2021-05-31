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
ll dp[100005];

int main()
{
    int n;
    cin >> n;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        vector<int> num;
        //cout << "i: " << i << endl;
        for(int j= 1; j*j <= i; j++){
            if(i%j == 0) {
                num.push_back(j);
                //cout << "j: " << j << endl;
                if(i/j != j && i/j != i) {
                    num.push_back(i/j);
                    //cout << "j; " << j << endl;
                }
            }
        }
        ll mx = 0;
        for(int j = 0; j < num.size(); j++){
            int now = num[j];
            //cout << now << endl;
            mx = max(mx, dp[now]);
            //cout << "dp[now]: " << dp[now] << endl;
        }
        dp[i] = mx+1;
    }
    for(int i = 1; i <= n; i++){
        cout << dp[i] << " ";
    }
    //cout << dp[n] << endl;
    cout << endl;
    return 0;
}