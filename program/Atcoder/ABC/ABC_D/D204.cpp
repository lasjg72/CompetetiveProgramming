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
#include <bitset> 

using namespace std;
using ll = long long;


int main()
{
    int n;
    cin >> n;
    vector<int> t(n);
    bitset<100005> dp;
    dp[0] = 1;
    int tot = 0;
    for(int i = 0; i < n; i++) {
        cin >> t[i];
        tot += t[i];
        dp |= dp<<t[i];
    }
    int ans = tot;
    for(int i = 0; i <= tot; i++){
        if(dp[i]) ans = min(ans, max(i, tot-i));
    }
    cout << ans << endl;
    return 0;
}