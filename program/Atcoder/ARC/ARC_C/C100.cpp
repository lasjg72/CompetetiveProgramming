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

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] = a[i] - (i+1);
    }
    sort(a.begin(), a.end());

    ll mid = a[n/2], ans = 0;
    for(int i = 0; i < n; i++){
        ans += abs(mid - a[i]);
    }
    cout << ans << endl;
    return 0;
}