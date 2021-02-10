#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include<iomanip>

using namespace std;

int main()
{
    int l;
    cin >> l;
    double ans = (double) l*l*l/27;
    cout << fixed;
    cout << setprecision(12) << ans << endl;
    return 0;
}