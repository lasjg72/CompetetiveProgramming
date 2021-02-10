#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int h, n, maxa=0;
    cin >> h >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        maxa = max(maxa, a[i]);
    }
    vector<long long> dp(h+maxa, 1001001001);
    dp[0] = 0;
    for (int i = 0; i < h+maxa; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i-a[j] < 0) continue;
            dp[i] = min(dp[i- a[j]] + b[j], dp[i]);
        }
    }
    long long ans = 1001001001;
    for(int i = h; i<h+maxa ; i++){
        ans = min(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}