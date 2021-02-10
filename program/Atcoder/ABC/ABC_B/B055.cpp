#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    ll ans = 1;
    for(int i = 1; i< n+1; i++){
        ans = ans * i % mod;
    }
    cout << ans << endl;
    return 0;
}