#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n);
    rep(i, n)
    {
        if (s[i] == 'R')
            a[i] = 0;
        if (s[i] == 'G')
            a[i] = 1;
        if (s[i] == 'B')
            a[i] = 2;
    }
    long long ans = 1;
    vector<int> cnt(3);
    rep(i, n) cnt[a[i]]++;
    rep(i, 3) ans *= cnt[i];
    rep(j, n) rep(i, j)
    {
        int k = j + (j - i);
        if (k < n)
        {
            if (a[i] == a[j])
                continue;
            if (a[j] == a[k])
                continue;
            if (a[k] == a[i])
                continue;
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}