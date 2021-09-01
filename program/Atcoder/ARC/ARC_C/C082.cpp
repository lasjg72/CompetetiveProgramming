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
    map<int, int> mp;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]-1]++;
        ans = max(ans, mp[a[i]-1]);
        mp[a[i]]++;
        ans = max(ans, mp[a[i]]);
        mp[a[i]+1]++;
        ans = max(ans, mp[a[i]+1]);
    }
    cout << ans << endl;
    return 0;
}