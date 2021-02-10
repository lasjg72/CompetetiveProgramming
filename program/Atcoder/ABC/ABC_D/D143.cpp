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
    vector<int> l(n);
    for(int i = 0; i< n; i++){
        cin >> l[i];
    }
    int ans = 0;
    sort(l.begin(), l.end());

    // for(int i = 0; i< n; i++){
    //     cout << l[i] << " ";
    // }
    // cout << endl;

    for(int i = 0; i< n-2; i++){
        for(int j = i+1; j< n-1; j++){
            //int mx = max(l[i]- l[j], l[j]-l[i]);
            ans += (lower_bound(l.begin(),l.end() ,l[i]+l[j])-l.begin())-j-1;
            
            //cout << ans << endl;
        }
    }
    cout << ans << endl;
    return 0;
}