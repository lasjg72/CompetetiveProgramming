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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    
    ll nc;
    for(ll i = 0; i < 1000000; i++){
        a += b;
        nc = c*(i+1);
        if(nc*d >= a){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}