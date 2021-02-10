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
    map<int, ll> card;
    set<ll> ca;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        ca.insert(a);
        card[a]++;
    }
    for(int i = 0; i< m; i++){
        int b, c;
        cin >> b >> c;
        card[c] += b;
        ca.insert(c);
    }
    ll ans = 0;
    ll num = n;

    // for(auto val: ca){
    //     cout << val << endl;
    // }

    for(auto itr = ca.end(); itr != ca.begin(); itr--){
        if(itr == ca.end()) itr--;
        ll tmp = *itr;
        //cout << "tmp: " << tmp << endl;
        if(num >= card[tmp]){
            num -= card[tmp];
            ans += tmp*card[tmp];
            //cout << "ans1: " << ans << endl;
        }else{
            ans += tmp*num;
            num = 0;
            break;
        }
    }
    if(num != 0) ans += num * (*ca.begin());
    cout << ans << endl;
    return 0;
}