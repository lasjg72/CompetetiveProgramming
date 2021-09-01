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
    double a;
    cin >> a;
    int c = (int)a;
    a = a - (int)a;
    a *= 10;
    int b = (int)a;
    if(0 <= b && b <= 2) cout << c << "-" << endl;
    else if(3 <= b && b <= 6) cout << c << endl;
    else if(7 <= b && b <= 9) cout << c << "+" << endl;
    return 0;
}