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
    string ans = "";
    while(n != 0) {
        int r = n%2;
        if(r < 0) r += 2;

        n = (n-r)/(-2);
        ans +=(r+'0');
    }

    reverse(ans.begin(), ans.end());
    if(ans == "") ans = "0";
    cout << ans << endl;
    return 0;
}