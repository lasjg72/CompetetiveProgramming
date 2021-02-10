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
#include <iomanip>

using namespace std;
using ll = long long;

int main()
{
    double x, y;
    cin >> x >> y;
    if(y == 0){
        cout << "ERROR" << endl;
        return 0;
    }
    //cout << floor(100 * (x / y)) / 100 << endl;
    cout << fixed << setprecision(2) << floor(100 * (x / y)) / 100 << endl;
    //cout << fixed << setprecision(2) << x/y << endl;
    return 0;
}