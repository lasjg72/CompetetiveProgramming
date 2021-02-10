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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a == b + c + d || b == a + c + d || c == b + a + d || d == b + c + a || a + b == c + d || a + c == b + d || a + d == b + c || b + c == a + d || b + d == a + c || c + d == a + b ){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}