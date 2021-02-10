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
    int n, m;
    cin >> n >> m;
    priority_queue<int> a;
    for(int i = 0; i < n; i++){
        int s;
        cin >> s;
        a.push(s);
    }
    for(int i = 0; i< m; i++){
        int tmp = a.top();
        a.pop();
        tmp /= 2;
        a.push(tmp);
    }
    ll ans = 0;
    for(int i = 0; i< n; i++){
        ans += a.top();
        a.pop();
    }
    cout << ans << endl;
    return 0;
}