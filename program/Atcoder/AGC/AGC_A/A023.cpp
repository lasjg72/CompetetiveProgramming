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
    int n;
    cin >> n;
    vector<ll> a(n), s(n+1, 0);
    map<ll, ll> seq;
    for(int i = 0; i< n; i++){
        cin >> a[i];
        s[i+1] = s[i] + a[i];
        seq[s[i+1]]++;
    }
    seq[0]++;
    auto combination = [&](ll x){
        return x * (x-1) / 2;
    };
    ll ans = 0;
    for(int i = 1; i< n+1; i++){
        if(seq[s[i]] > 1){
            ans += combination(seq[s[i]]);
            seq[s[i]] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}