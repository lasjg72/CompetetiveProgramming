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
    ll n, a, x, y;
    cin >> n >> a >> x >> y;
    if(n > a){
        cout << a*x + (n-a)*y << endl;
    }else{
        cout << n*x << endl;
    }
    return 0;
}