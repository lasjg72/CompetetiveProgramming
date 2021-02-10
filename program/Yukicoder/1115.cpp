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

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), num(n);
    for(int i = 0; i< n; i++){
        cin >> a[i];
        num[a[i]] = i;
    }
    sort(a.begin(), a.end());
    vector<int> b(n);
    for(int i = 0; i< n; i++){
        cin >> b[i];
    }
    ll ans = 0, tmp = 0;
    for(int i = 0; i< n; i++){
        int pos = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        if(num[a[pos]] + tmp == i) continue;
        ans += abs(num[a[pos]]+tmp-i);
        tmp++;
        cout << ans << endl;
        cout << tmp << endl;
    }
    cout << ans << endl;
    return 0;
}