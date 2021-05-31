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
    ll k;
    cin >> k;
    vector<ll> a, b, c, tmp, num;
    ll ans = 0;
    for(int i = 1; i <= k; i++){
        int bc = k/i;
        for(int j = 1; j <=bc; j++){
            int now = bc/j;
            for(int k = 1; k <= now; k++){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
