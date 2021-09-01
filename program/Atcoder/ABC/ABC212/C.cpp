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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 1001001001;
    for(int i = 0; i < n; i++){
        int pos = lower_bound(b.begin(), b.end(), a[i])-b.begin();
        ans = min(ans, abs(a[i]-b[pos]));
        if(pos != 0) ans = min(ans, abs(a[i]-b[pos-1]));
    }
    cout << ans << endl;
    return 0;
}