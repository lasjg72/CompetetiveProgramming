#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main()
{
    ll a, b, x;
    cin >> a >> b >> x;
    if(a+b > x){
        cout << 0 << endl;
        return 0;
    }
    auto keta = [&](ll n){
        int res = 0;
        while(n != 0){
            n /= 10;
            res++;
        }
        return res;
    };
    auto func = [&](ll n){
        return a * n + b * keta(n);
    };
    
    ll l = 0, r = 1000000001;
    
    while(r-l > 1){
        ll c = (r+l)/2;
        if(func(c) <= x){
            l = c;
        }else{
            r = c;
        }
    }
    cout << l << endl;
    return 0;
}