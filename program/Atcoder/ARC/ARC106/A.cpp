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
    for(ll i = 1; i < 50; i++){
        for(ll j = 1; j < 50; j++){
            ll a = 3, b = 5;
            for(int k = 1; k < i; k++){
                if((double)a * 3 > 2e18) break;
                a *= 3;
                //cout << a << endl;
            }
            for(int l = 1; l < j; l++){
                if((double)b * 5 > 2e18) break;
                b *= 5;
                //cout << b << endl;
            }
            if((double)a + b > 2e18) break;
            if(a + b == n){
                //cout << "a: " << a << "b: " << b << endl;
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}