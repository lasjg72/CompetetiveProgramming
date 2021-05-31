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
    ll r, x, y;
    cin >> r >> x >> y;
    ll dist = x*x + y*y;
    //cout << dist << endl;
    ll ans = 0;
    if(dist < r*r){
        cout << 2 << endl;
        return 0;
    }
    for(ll i = 1; i <= 1000000; i++){
        if(i*i*r*r >= dist){
            ans = i;
            break;
        }
    } 
    cout << ans << endl;
    return 0;
}