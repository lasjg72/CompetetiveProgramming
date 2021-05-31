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
const int INF = 1001001001;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        dp[i] = INF;
    }
    for(int i = 0; i < n; i++){
        dp[lower_bound(dp, dp+n, a[i])-dp] = a[i];
    }
    cout << lower_bound(dp, dp+n, INF)-dp << endl;
    return 0;
}