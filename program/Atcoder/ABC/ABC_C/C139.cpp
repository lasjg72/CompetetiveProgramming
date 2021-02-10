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
    vector<int> h(n);
    ll tmp = 0, ans = -1;
    for(int i = 0; i < n; i++){
        cin >> h[i];
        if(i != 0){
            if(h[i] <= h[i-1]) {
                tmp++;
                //cout << "tmp: " << tmp << endl;
            }
            else{
                //cout << "i: " << i << endl;
                ans = max(ans, tmp);
                //cout << ans << endl;
                tmp = 0;
            }
        }
    }
    ans = max(ans, tmp);
    cout << ans << endl;
    return 0;
}