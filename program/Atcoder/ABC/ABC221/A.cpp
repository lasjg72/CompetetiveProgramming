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
    int a, b;
    cin >> a >> b;
    int ans = 1;
    for(int i = 0; i < (a-b); i++){
        ans *= 32;
    }
    cout << ans << endl;
    return 0;
}