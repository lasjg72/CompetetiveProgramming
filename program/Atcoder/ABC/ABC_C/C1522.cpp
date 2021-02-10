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
    int mi = 1001001001;
    int ans = 0;
    for(int i = 0; i< n; i++){
        int p;
        cin >> p;
        if(mi > p){
            ans++;
            mi = p;
        }
    }
    cout << ans << endl;
    return 0;
}