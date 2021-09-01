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

ll mpow(ll x, ll n){
    if(n == 0) return 1;
    else if(n%2 == 0) return mpow(x, n/2)*mpow(x, n/2);
    else return mpow(x, n-1)*x;
}

ll calc(ll n){
    // cout << "------" << endl;
    // cout << "n: " << n << endl;
    ll  tmp = n;
    int num = 1;
    while(tmp > 9){
        tmp /= 10;
        num++;
    }
    string s = "";
    bool flag = false;
    for(int i = num-1; i >= 0; i--){
        if(flag) break;
        //cout << "n: " << n << endl;
        if((ll)(n/mpow(10, i)) > 3){ //確定
            for(int j = 0; j < i+1; j++) s += '3';
            flag = true;
        }
        else if((ll)(n/mpow(10, i)) == 3){
            string hoge = "3";
            for(int j = 0; j < i; j++) hoge += '1';
            if(n <= stoll(hoge)){ //確定
                if(n == stoll(hoge)){
                    s += hoge;
                }else{
                    s += '2';
                    for(int j = 0; j < i; j++) s += '3';
                }
                flag = true;
            }else{ //未確定
                s += '3';
                n -= (ll)(n/mpow(10,i))*mpow(10, i);        
            }
        }
        else if((ll)(n/mpow(10, i)) == 2){
            string hoge = "2";
            for(int j = 0; j < i; j++) hoge += '1';
            if(n <= stoll(hoge)){ //確定
                if(n == stoll(hoge)){
                    s += hoge;
                }else{
                    s += '1';
                    for(int j = 0; j < i; j++) s += '3';
                }
                flag = true;
            }else{ //未確定
                s += '2';
                n -= (ll)(n/mpow(10,i))*mpow(10, i);        
            }
        }
        else if((ll)(n/mpow(10, i)) == 1){
            string hoge = "1";
            for(int j = 0; j < i; j++) hoge += '1';
            if(n <= stoll(hoge)){ //確定
                if(n == stoll(hoge)){
                    s += hoge;
                }else{
                    s += '3';
                    for(int j = 0; j < i-1; j++) s += '3';
                }
                flag = true;
            }else{ //未確定
                s += '1';
                n -= (ll)(n/mpow(10,i))*mpow(10, i);        
            }
        }
    }
    ll res = stoll(s);
    return res;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        int ans = 0;
        while(n != 0){
            ll res = calc(n);
            if(res == 0) break;
            n -= res;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}