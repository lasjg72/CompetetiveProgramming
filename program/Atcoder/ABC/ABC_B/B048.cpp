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
    ll a, b, x;
    cin >> a >> b >> x;
    if(a == 0){
        cout << b / x + 1 << endl;
    }else{
        cout << b/x - (a-1)/x << endl;
    }
    return 0;
}