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
    ll a, b, c;
    cin >> a >> b >> c;
    ll x = b-a;
    ll y = c-b;
    ll ans = 0;
    if(x == y){
        cout << ans << endl;
    }else if(x > y){
        cout << abs(y-x) << endl;   
    }else{
        ans += ceil((double)abs(x-y)/2);
        b += ans;
        x = b-a;
        y = c-b;
        if(x == y) cout << ans << endl;
        else{
            ans += abs(x-y);
            cout << ans << endl;
        }
    }
    return 0;
}