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
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 1; i <= n-1; i++){
        ans += i;
    }
    cout << ans << endl;
    return 0;
}