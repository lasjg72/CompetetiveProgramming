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

int main()
{
    double w, h, x, y;
    cin >> w >> h >> x >> y;
    if(x == w/2 && y == h/2){
        double a = w*h;
        double ans = a/2;
        cout << ans << " " << 1 << endl;
    }else{
        double a = w*h;
        double ans = a/2;
        cout << ans << " " << 0 << endl;
    }
    return 0;
}