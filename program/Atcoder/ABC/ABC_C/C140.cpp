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
    vector<int> a(n), b(n-1);
    for(int i = 0; i < n-1; i++){
        cin >> b[i];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(i == 0) a[i] = b[i];
        else if(i == n-1) a[i] = b[i-1];
        else a[i] = min(b[i], b[i-1]);
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}