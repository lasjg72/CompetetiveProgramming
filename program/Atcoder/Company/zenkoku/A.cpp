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
    int n, a, b;
    cin >> n >> a >> b;
    cout << min(a, b) << " ";
    if(a+b <= n) cout << 0 << endl;
    else cout << (a+b)-n << endl;
    return 0;
}