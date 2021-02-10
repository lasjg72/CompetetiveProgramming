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
    int n;
    cin >> n;
    int p;
    vector<bool> dp(10010, false);
    dp[0] = true;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        for (int j = (i + 1) * 100 + 1; j >= 0 ; j--)
        {
            if (dp[j])
            {
                dp[j + p] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n * 100; i++)
    {
        if (dp[i])
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}