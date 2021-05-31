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
    ll ans = 0;
    vector<ll> rem(k, 0);
    for(int i = 1; i <= n; i++) rem[i%k]++;
    for(int a = 0; a < k; a++){
        int b = (k-a)%k;
        int c = (k-a)%k;
        if((b+c)%k != 0) continue;
        ans += rem[a]*rem[b]*rem[c];
    }
    cout << ans << endl;
    return 0;
}