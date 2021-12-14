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

vector<ll> prime_factorize(long long N) {
    vector<ll> res;
    ll num = 0;
    for (long long a = 1; a * a <= N; a++) {
        num = max(num, a);
        if (N % a != 0) continue;
        res.push_back(a);
    }
    if(num * num != N) res.push_back(num);
    return res;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> p = prime_factorize(n);
    
    ll ans = 0;
    sort(p.begin(), p.end());
    int size = p.size()-1;
    
    for(ll now : p){
        ans += now;
        if(size > 0) ans += n/now;
        size--;
    }
    cout << ans << endl;
    return 0;
}