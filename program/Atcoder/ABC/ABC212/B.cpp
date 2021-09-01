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
    int s;
    cin >> s;
    int a, b, c, d;
    d = s%10;
    s /= 10;
    c = s%10;
    s /= 10;
    b = s%10;
    s /= 10;
    a = s%10;
    //cout << "a: " << a << b << c << d << endl;
    if(a == b && b == c && c == d && a == d){
        cout << "Weak" << endl;
    }else if(b == (a+1)%10 && c == (b+1)%10 && d == (c+1)%10){
        cout << "Weak" << endl;
    }else{
        cout << "Strong" << endl;
    }
    return 0;
}