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
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] %= 2;
        mp[a[i]]++;
    }
    ll ans;
    if(mp[1] == 0){
        if(p == 1) ans = 0;
        else ans = 1LL<<n;
    }else{
        ans = 1LL<<(n-1);
    }
    cout << ans << endl;
    return 0;
}