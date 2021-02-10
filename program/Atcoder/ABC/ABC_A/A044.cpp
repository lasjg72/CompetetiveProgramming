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
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    int ans = 0;
    if(n > k){
        ans += x * k;
        ans += (n-k)*y;
    }else{
        ans += x*n;
    }
    cout << ans << endl;
    return 0;
}