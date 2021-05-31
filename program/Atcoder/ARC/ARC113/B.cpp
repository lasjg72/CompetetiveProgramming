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

ll solve(ll a, ll b){
    a%=10;
    if(a == 0) return 0;
    if(a == 1 || a == 5 || a == 6){
        return a;
    }else{
        b %= 4;
        for(int i = 1; i < b; i++){
            a = (a*a)%10;
        }
        return a;
    }
}

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    a %= 10;
    if(a == 0){
        cout << 0 << endl;
        return 0;
    }
    if(c >= 100){
        if(b >= 5){

        }
        else{
        for(int i = 0; i < 100; i++){
            b *= b;
            if(b>=5) break;
        }
        }
    }else{
        for(int i = 0; i < c; i++){
            b *= b;
            if(b>=5) break;
        }
    }
    ll num = b % 4;
    for(ll i = 0; i < c%b; i++){
        num *= num;
        num %= a;
    }
    //cout << num << endl;
    cout << solve(a, num) << endl;
    return 0;
}