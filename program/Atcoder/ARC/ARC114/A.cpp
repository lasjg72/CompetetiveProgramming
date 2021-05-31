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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main()
{
    int n;
    cin >> n;
    vector<int> x(n), p(51, 0), prime;
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    for(int i = 2; i <= 50; i++){
        if(p[i] == 0){
            prime.push_back(i);
            for(int j = i; j <= 50; j+=i){
                p[j]++;
            }
        }
    }
    ll ans = 1001001001001001001;
    for(int bit = 0; bit < (1 << prime.size()); bit++){
        ll now = 1;
        for(int i = 0; i < prime.size(); i++){
            if(bit & (1 << i)){
                now *= prime[i];
            }
        }
        bool ok = true;
        for(int i = 0; i < n; i++){
            if(gcd(x[i], now) == 1){
                ok = false;
                break;
            }
        }
        if(ok){
            ans = min(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}