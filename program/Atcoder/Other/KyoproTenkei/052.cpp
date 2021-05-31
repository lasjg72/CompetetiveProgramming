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

const int mod = 1e9+7;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(6));
    vector<int> num(n, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            cin >> a[i][j];
            num[i] += a[i][j];
        }
    }
    ll ans = 1;
    for(int i = 0; i < n; i++){
        ans = 1LL*ans*num[i]%mod;
    }
    cout << ans << endl;
    return 0;
}