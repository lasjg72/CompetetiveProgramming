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

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<int>> que;
    for(int i = 0; i< n; i++){
        cin >> a[i] >> b[i];
        que.push({a[i], b[i]});
    }
    ll ans = 0;
    for(int i = 0; i<k;i++){
        int a = que.top().first;
        int b = que.top().second;
        que.pop();
        ans += a;
        que.push({a+b, b});
    }
    cout << ans << endl;
    return 0;
}