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
    vector<int> a(n);
    ll tot = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        tot += a[i];
    }
    ll x;
    cin >> x;
    ll ans = x/tot*n;
    x -= x/tot*tot;
    ll tmp = 0;
    for(int i = 0; i < n; i++){
        tmp += a[i];
        if(tmp > x){
            ans += i+1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}