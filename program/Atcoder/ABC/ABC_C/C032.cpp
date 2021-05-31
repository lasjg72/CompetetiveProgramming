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
    vector<ll> s(n);
    bool zero = false;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        if(s[i] == 0) zero = true;
    }
    if(zero){
        cout << n << endl;
        return 0;
    }
    ll tot = 1;
    int ans = 0, r = 0;
    for(int i = 0; i < n; i++){
        if(r == i && s[i] > k) {
            r++;
            continue;
        }
        while(r < n && tot <= k){
            tot *= s[r];
            if(tot > k){
                tot /= s[r];
                break;
            }
            r++;
        }
        tot /= s[i];
        ans = max(ans, r-i);
    }
    cout << ans << endl;
    return 0;
}