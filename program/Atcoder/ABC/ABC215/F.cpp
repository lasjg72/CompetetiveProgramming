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
using P = pair<ll, ll>;

int main()
{
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    vector<P> nx(n), ny(n);
    for(int i = 0; i < n; i++){
        nx[i] = {x[i], y[i]};
        ny[i] = {y[i], x[i]};
    }
    sort(nx.begin(), nx.end());
    sort(ny.begin(), ny.end());
    ll l = -1, r = 1001001001;
    while(r-l > 1){
        cout << "---" << endl;
        cout << l << " " << r << endl;
        ll mid = (r+l)/2;
        vector<ll> tmp(n);
        for(int i = 0; i < n; i++) tmp[i] = nx[i].first;
        bool ok = false;
        for(int i = 0; i < n; i++){
            auto itr = lower_bound(tmp.begin(), tmp.end(), tmp[i]+mid);
            if(itr == tmp.end()) continue;
            ok = true;
            int lx = itr-tmp.begin();
            if(nx[lx].second <= mid){
                r = mid;
                break;
            }else{
                l = mid;
                break;
            }
        }
        if(!ok) r = mid;
    }
    cout << (r+l)/2 << endl;
    return 0;
}