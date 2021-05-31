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
    double a, b;
    cin >> a >> b;
    double x = b/a;
    cout << (1-x)*100 << endl;
    return 0;
}
