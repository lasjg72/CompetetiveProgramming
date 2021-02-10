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
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll m = 0;
    ll ans = 0;
    for(int i = 0; i< n; i++){
        if(a[i] < m){
            ans += m-a[i];
        }else{
            m = a[i];
        }
    }
    cout << ans << endl;
    return 0;
}