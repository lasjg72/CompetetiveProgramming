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
    ll n;
    cin >> n;
    vector<ll> a(n), t(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> t[i];
    }
    ll ans = -1001001001001001001, x = 0;
    ll num = n-1, tot = 0;
    while(t[num] == 1){
        num--;
        tot += a[num];
    }
    pair<ll, ll> p;
    for(int i = num; i >= 0; i--){
        if(i == num){
            if(t[i] == 2){
                x = a[i];
                p.first = 
            }else if(t[i] == 3){
                x = a[i];
                p.first = a[i];
                p.second = x;
            }    
        }else{

            if(t[i] == 1){

            }else if(t[i] == 2){

            }else if(t[i] == 3){

            }
        }
    }
    return 0;
}