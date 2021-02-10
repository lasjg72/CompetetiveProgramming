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
const int mod = 1e9;

int main()
{
    int a, b;
    cin >> a >> b;
    int x = 0, y = 0;
    x = (a+b)/2;
    y = (a-b)/2;
    cout << x << " " << y << endl;
    return 0;
}