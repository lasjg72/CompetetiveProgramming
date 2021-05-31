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
    int n;
    double D, H;
    cin >> n >> D >> H;

    double nh = H, nd = D;
    double ans = 0;
    for(int i = 0; i < n; i++){
        double d, h;
        cin >> d >> h;
        double nx = (H-h)/(D-d);
        ans = max(ans, H-nx*D);
    }
    printf("%.4f\n", ans);
    return 0;
}