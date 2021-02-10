#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;
#define PI 3.141592653589793

int main()
{
    int a, b, x;
    cin >> a >> b >> x;
    if(x == a*a*b){
        cout << 0 << endl;
        return 0;
    }
    double e = a*a*b - x; //空き容量
    //傾けた時の水面の長さの二乗
    double f = (2*e/(a*a))*(2*e/(a*a)) + a*a;
    cout << "e: " << e << endl;
    cout << "f: " << f << endl;
    double g = 2*e/(a*a);
    cout << "tan: " << atan(g/a) * 180.0 / PI << endl;;
    f = sqrt(f);
    double ans = acos(a/f) * 180.0 / PI;
    cout << ans << endl;
    return 0;
}