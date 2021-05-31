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
    int n, K;
    cin >> n >> K;
    vector<ll> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    ll ans = 0;
    for(int i = 0; i <= min(n, K); i++){
        for(int j = 0; i+j <= min(n, K); j++){
            ll cur = 0;
            vector<ll> tmp;
            for(int k = 0; k < i; k++) tmp.push_back(v[k]), cur += v[k];
            //cout << cur << endl;
            for(int k = 0; k < j; k++) tmp.push_back(v[n-1-k]), cur += v[n-1-k];
            //cout << cur << endl;
            sort(tmp.begin(), tmp.end());
            //cout << "min: " << min(n, K)-(i+j) << endl;
            //cout << "size: " << (int)tmp.size() << endl;
            for(int k = 0; k < min(K-(i+j), (int)tmp.size()); k++) if(tmp[k] < 0) cur -= tmp[k];
            ans = max(ans, cur);
        }
    }
    cout << ans << endl;
    return 0;
}