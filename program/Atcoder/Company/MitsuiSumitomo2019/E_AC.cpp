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
const int mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> num;
    ll ans = 1;
    num[0] = 3;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        //if(a[0] != 0) cout << "error" << endl;
        ans = (ans*num[a[i]])%mod;
        num[a[i]]--;
        num[a[i]+1]++;
    }
    cout << ans << endl;
    return 0;
}