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
    vector<int> a(n+1, 0);
    for(int i = 2; i <= n; i++){
        if(a[i] != 0) continue;
        for(int j = i; j <= n; j += i) a[j]++;
    }
    int ans = 0;
    for(int i = 2; i <= n; i++){
        if(a[i] >= k) ans++;
    }
    cout << ans << endl;
    return 0;
}