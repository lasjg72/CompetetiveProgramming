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
    for(int i = 0; i < n; i++) cin >> a[i];
    int num = 0;
    for(int i = 0; i <= k; i++){
        for(int j = 0; j < n; j++){
            if(i-a[j] >= 0 && dp[i-a[j]] == 0) dp[i] = 1;        
        }
    }
    string ans;
    if(dp[k] == 1) ans = "First";
    else ans = "Second";
    cout << ans << endl;
    return 0;
}