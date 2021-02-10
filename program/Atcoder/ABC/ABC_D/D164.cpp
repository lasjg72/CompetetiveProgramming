#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <chrono>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    vector<int> cnt(2019);
    int ans = 0, total = 0, x = 1;

    for (int i = 0; i < n; i++)
    {
        cnt[total]++;
        total += (s[i] - '0') * x;
        total %= 2019;
        ans += cnt[total];
        x = x * 10 % 2019;
    }

    cout << ans << endl;
    return 0;
}