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

vector<ll> calc_divisor(int n){
    vector<ll> res;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            res.push_back(i);
            int j = n / i;
            if(j != i) res.push_back(j);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> res = calc_divisor(m);
    ll ans = 1;
    for(auto d : res){
        if(n * d <= m) ans = max(ans, d);
    }
    cout << ans << endl;
    return 0;
}