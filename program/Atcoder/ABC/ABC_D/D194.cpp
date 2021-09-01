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
    double ans = 0;
    for(int i = 1; i < n; i++){
        ans += (double)n/i;
    }
    if(ans == 0) ans = 1.0;
    printf("%.7f\n", ans);
    return 0;
}