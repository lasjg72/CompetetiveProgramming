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
    int a, b;
    cin >> a >> b;
    int ans = max(max(a+b, a-b), a*b);
    cout << ans << endl;
    return 0;
}