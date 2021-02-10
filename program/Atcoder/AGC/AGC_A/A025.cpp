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
    int ans = 1001001001;
    for(int i = 1; i <n; i++){
        int b = n - i;
        string s, t;
        int tmp = 0;
        s = to_string(i);
        t = to_string(b);
        for(int j = 0; j < s.length(); j++){
            tmp += s[j] - '0';
        }
        for(int k = 0; k< t.length(); k++){
            tmp += t[k] - '0';
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}