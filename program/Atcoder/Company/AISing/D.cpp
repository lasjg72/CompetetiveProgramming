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
    string x;
    cin >> x;
    ll t = 0, num = 0;
    for(int i = 0; i < n; i++){
        if(x[i] == 1){
            t += n-i-1;
            num++;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ll t2 = t;
        if(x[i-1] == 1){
            t2 -= n-(i-1)-1;
            num--;
        }else{
            t2 += n-(i-1)-1;
            num++;
        }

        if(t2 % num == 0){
            ans = 1;
        }else{
            ans = 2;
        }

        if(x[n-1] == 1) ans++;
        cout << ans << endl;
    }
    return 0;
}