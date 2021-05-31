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
    ll s;
    cin >> s;
    ll x1 = 0, x2 = 1e9, x3, y1 = 0, y2 = 1, y3;
    for(int i = 1; i <= 1e9; i++){
        y3 = i;
        x3 = 1000000000 * y3 - s;
        if(x3 < 0) continue;
        else break;
    }
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
    return 0;
}