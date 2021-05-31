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
    int a, b, c;
    cin >> a >> b >> c;
    a %= 10;
    int x;

    

    int ans = pow(a, (x%4)+1);
    ans %= 10;
    cout << ans << endl;
    return 0;
}