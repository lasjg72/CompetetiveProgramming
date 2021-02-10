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
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    int mx = max(a, b);
    mx = max(mx, c);
    ans += (mx-a)/2;
    a += (mx-a)/2 * 2;
    ans += (mx-b)/2;
    b += (mx-b)/2 * 2;
    ans += (mx-c)/2;
    c += (mx-c)/2 * 2;

    if( (a < mx && b < mx) || (b < mx && c < mx) || (a < mx && c < mx) ){
        ans += 1;
    }else if(a == b && b == c){
    }else{
        ans += 2;
    }
    cout << ans << endl;
    return 0;
}