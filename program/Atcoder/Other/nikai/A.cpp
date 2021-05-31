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
    double x, y, z;
    cin >> x >> y >> z;
    int ans;
    for(int i = 1; i <= 1000000; i++){
        if(y/x <= (double)i/z) {
            ans = i-1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}