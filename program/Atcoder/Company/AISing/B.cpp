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
    vector<int> a(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if((i+1)%2 == 1 && a[i] % 2 == 1){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}