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

int main()
{
    ll b, c;
    cin >> b >> c;
    ll mican1 = b - c/2;
    ll mican2 = -b -(c-1)/2;
    ll mi = min(mican1, mican2);
    //cout << mi << endl;
    ll mxcan1 = -(b - (c-1)/2);
    ll mxcan2 = -(-b-(c-2)/2);
    ll mx = max(mxcan1, mxcan2);
    //cout << mx << endl;
    //cout << abs(b)*2 + 1 << endl;
    //cout << c << endl;
    if(b != 0 && c == 1){
        cout << 2 << endl;
        return 0;
    }
    if(abs(b)*2 + 1 > c){
        ll num1 = b - c/2; //下はどこまでいけるか
        ll num2 = -b - (c-1)/2; //反転してどこまでいけるか

        if(c % 2 == 0){
            ll ans1 = abs(b-num1)+1+abs(b-num1);
            ll ans2 = abs(-b-num2)+1+abs(-b-num2)+1;
            cout << ans1+ans2-2 << endl;
        }else{
            ll ans1 = abs(b-num1)+1+abs(b-num1)+1;
            ll ans2 = abs(-b-num2)+1+abs(-b-num2);
            cout << ans1+ans2-2 << endl;
        }
    }else{
        if(mx >= 0){
            cout << mx - mi + 1;
        }else{
            cout << abs(mi) - abs(mx) + 1;
        }
    }
    return 0;
}