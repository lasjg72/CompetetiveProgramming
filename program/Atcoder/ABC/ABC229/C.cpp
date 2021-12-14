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
    int n, w;
    cin >> n >> w;
    vector<pair<ll, ll>> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p.rbegin(), p.rend());
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(w-p[i].second >= 0){
            w -= p[i].second;
            ans += p[i].first*p[i].second;
        }else{
            ans += p[i].first*w;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}