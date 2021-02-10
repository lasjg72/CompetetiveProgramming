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
    vector<int> x(n), y(n), p(n);
    for(int i = 0; i< n; i++){
        cin >> x[i] >> y[i] >> p[i];
    }
    vector<ll> ans(n, 1001001001);

    ll xt = 0, yt = 0, to = 0;
    for(int i = 0; i< n; i++){
            for(int j = 0; j< n; j++){
                xt += abs(x[j])*p[j];
            }
            for(int j = 0; j< n; j++){
                yt += abs(y[j])*p[j];
            }
            to = min(xt, yt);
    }
    ans[0] = to;
    
    for(int bit = 0; bit < (1 << n); bit++){
        int num = 0;
        ll xtotal = 0, ytotal = 0, total = 0;
        for(int i = 0; i< n; i++){
            if(bit & (1 << i)){
                for(int j = 0; j< n; j++){
                    xtotal += abs(x[i]-x[j])*p[j];
                }
                for(int j = 0; j< n; j++){
                    ytotal += abs(y[i]-y[j])*p[j];
                }
                total = min(xtotal, ytotal);
                num++;
            }
        }
        ans[num] = min(ans[num], total);
    }

    for(int i = 0; i<n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}