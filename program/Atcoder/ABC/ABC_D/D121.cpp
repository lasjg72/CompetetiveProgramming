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
    ll a, b;
    cin >> a >> b;
    a -= 1;
    if(a%2 == 0){
        if((a/2)%2 == 1){
            a ^= 1;
        }else{
            a ^= 0;
        }
    }else{
        if(((a+1)/2)%2 == 0){
            a = 0;
        }else{
            a = 1;
        }
    }

    if(b%2 == 0){
        if((b/2)%2 == 1){
            b ^= 1;
        }else{
            b ^= 0;
        }
    }else{
        if(((b+1)/2)%2 == 0){
            b = 0;
        }else{
            b = 1;
        }
    }
    ll ans = a^b;
    cout << ans << endl;
    return 0;
}
