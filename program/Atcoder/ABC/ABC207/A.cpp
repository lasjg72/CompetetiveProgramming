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
    vector<int> a(3);
    for(int i = 0; i < 3; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    cout << a[0]+a[1] << endl;
    return 0;
}
