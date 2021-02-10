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
    int n, d;
    cin >> n >> d;
    int ans = 0;
    for(int i = 0; i < n; i++){
        double x, y;
        cin >> x >> y;
        double dis = sqrt(x*x + y * y);
        if(dis <= d) ans++;
    }
    cout << ans << endl;
    return 0;
}