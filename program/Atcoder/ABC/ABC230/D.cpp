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
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].second >> p[i].first;
    }
    sort(p.begin(), p.end());
    int ans = 0, now = -1;
    for(int i = 0; i < n; i++){
        int l = p[i].second, r = p[i].first;
        //cout << l << " " << r << " " << now << endl;
        if(l <= now) continue;
        ans++;
        now = r+d-1;
    }
    cout << ans << endl;
    return 0;
}