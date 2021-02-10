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
    int n, t;
    cin >> n >> t;
    vector<int> ti(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> ti[i];
        if(i != 0){
            if(ti[i]- ti[i-1] >= t) ans += t;
            else ans += ti[i]-ti[i-1]; 
        }
    }
    ans += t;
    cout << ans << endl;
    return 0;
}
