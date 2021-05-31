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
    vector<ll> a(n), sum(n+1, 0), sumsum(n+2, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum[i+1] = sum[i] + a[i];
        sumsum[i+1] = sumsum[i] + sum[i];
    }
    sumsum[n+1] = sumsum[n] + sum[n];
    priority_queue<ll> q;
    for(int i = 0; i < n; i++){
        ll ans = 0;
        q.push(a[i]);
        ll mx = q.top();
        ans += mx*(i+1)+sum[i+1]+sumsum[i+1];
        cout << ans << endl;
    }
    return 0;
}