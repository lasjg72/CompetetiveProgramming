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
    vector<int> d(n);
    map<int, int> a;
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    int ans = 0, mid = 0;
    mid = n/2;
    if(d[mid] != d[mid -1]){
        ans = d[mid] - d[mid-1];
    }
    // for(int i = 0; i < n; i++){
    //     cout << d[i] << " ";
    // }
    // cout << endl;
    cout << ans << endl;
    return 0;
}
