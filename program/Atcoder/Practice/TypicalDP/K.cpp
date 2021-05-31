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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    dp[0] = 0;
    for(int i = 1; i <= k; i++){
        for(int j = 0; j < n; j++){
            if(i-a[j] >= 0 && dp[i-a[j]] == 0) dp[i] = 1;
            //if(i-a[j] >= 0) dp[i] = (dp[i-a[j]] + 1)%2;
            //cout << "dp[" << i << "]: " << dp[i] << endl;
        }
    }
    if(dp[k] == 1){
        cout << "First" << endl;
    }else{
        cout << "Second" << endl;
    }
    return 0;
}