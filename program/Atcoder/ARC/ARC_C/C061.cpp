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
    string s;
    cin >> s;
    int n = s.size();
    long long ans = 0;
    for (int bit = 0; bit < (1 << (n - 1)); bit++)
    {
        long long tmp = 0;
        for (int i = 0; i < n - 1; i++)
        {
            tmp *= 10;
            tmp += s[i] - '0';
            if (bit & (1 << i))
            {
                ans += tmp;
                tmp = 0;
            }
        }
        tmp *= 10;
        tmp += s.back() - '0';
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}