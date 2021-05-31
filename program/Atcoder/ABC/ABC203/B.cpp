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
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            ans += i*100+j;
        }
    }
    cout << ans << endl;
    return 0;
}