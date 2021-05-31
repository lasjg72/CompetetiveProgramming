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
ll ans;
int n;
string s;
const ll INF = 1001001001001001001;

int main()
{
    cin >> n >> s;
    vector<ll> a(n), mx(n+1, 0), mi(n+1, 0);
    ll ans1 = -INF, ans2 = INF;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(s[i] == 'B') a[i] *= -1;
        if(i == 0){
            mx[i] = a[i];
            mi[i] = a[i];
        }else{
            mx[i] = max(mx[i-1]+a[i], a[i]);
            mi[i] = min(mi[i-1]+a[i], a[i]);
        }
        ans1 = max(ans1, mx[i]);
        ans2 = min(ans2, mi[i]);
    }

    cout << max(ans1, -ans2) << endl;
    return 0;
}