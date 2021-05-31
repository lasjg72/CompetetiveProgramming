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
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> x(n, vector<ll>(3));
    for(int i = 0; i < n; i++){
        cin >> x[i][0] >> x[i][1] >> x[i][2];
    }
    ll ans = 0;
    for(int bit = 0; bit < 8; bit++){
        vector<ll> tot;
        ll now = 0;
        for(int i = 0; i < n; i++){
            ll tmp = 0;
            for(int j = 0; j < 3; j++){
                if(bit&(1<<j)){
                    tmp -= x[i][j];
                }else tmp += x[i][j];
            }
            tot.push_back(tmp);
        }
        sort(tot.rbegin(), tot.rend());
        for(int i = 0; i < m; i++){
            now += tot[i];
        }
        ans = max(now, ans);
    }
    cout << ans << endl;
    return 0;
}