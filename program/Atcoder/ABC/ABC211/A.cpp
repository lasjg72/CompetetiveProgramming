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
    double c = (a-b)/3+b;
    printf("%.6f\n", c);
    return 0;
}