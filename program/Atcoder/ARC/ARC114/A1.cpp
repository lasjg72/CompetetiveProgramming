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
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    sort(x.rbegin(), x.rend());
    ll ans = 1;
    vector<bool> use(100, false);
    vector<ll> res;
    for(int i = 0; i < n; i++){
        bool now = false;
        for(int j = 2; j*j <= x[i]; j++){
            if(x[i]%j != 0) continue;
            int tmp = x[i];
            while(x[i] % j == 0){
                now = true;
                x[i] /= j;
            }
            res.push_back(j);
            if(use[j] == false && use[tmp/j] == false){
                ans *= (ll)j;
                // cout << "j: " << j << endl;
                // cout << ans << endl;
                use[j] = true;
            }
        }
        if(x[i] != 1) {
            res.push_back(x[i]);
            if(use[x[i]] == false && now == false) {
                ans *= (ll)x[i];
                use[x[i]] = true;
            }
        }
    }
    return 0;
}