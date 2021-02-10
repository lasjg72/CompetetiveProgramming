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
    string a, b;
    cin >> a >> b;
    int x = a[0]-'0';
    int y = a[1]-'0';
    int z = a[2]-'0';
    int c = x + y + z;
    x = b[0] - '0';
    y = b[1] - '0';
    z = b[2] - '0';
    int d = x + y + z;
    cout << max(c, d) << endl;
    return 0;
}