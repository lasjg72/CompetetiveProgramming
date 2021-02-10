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
    ll n;
    cin >> n;
    vector<ll> f(n+1, 0);
    for(int i = 1; i < n+1; i++){
        for(int j = i; j < n+1; j = j + i){
            f[j]++;
        }
    }
    ll ans = 0;
    for(int i = 1; i< n+1; i++){
        ans += i * f[i];
    }
    cout << ans << endl;
    return 0;
}