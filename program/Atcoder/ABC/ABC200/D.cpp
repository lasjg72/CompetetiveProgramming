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
    vector<ll> a(n);
    vector<set<ll>> st(200);
    vector<vector<ll>> ans(200);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int num = min(8, n);
    for(int bit = 1; bit < (1<<num); bit++){
        ll tmp = 0;
        vector<ll> tans;
        for(int i = 0; i < num; i++){
            if(bit&(1<<i)){
                tmp = (tmp+a[i])%200;
                tans.push_back(i+1);
            }
        }
        if(st[tmp%200].size() > 0){
            cout << "Yes" << endl;
            cout << tans.size();
            for(int z: tans){
                cout << " " << z;
            }
            cout << endl;
            cout << ans[tmp%200].size();
            for(int z: ans[tmp%200]){
                cout << " " << z;
            }
            cout << endl;
            return 0;
        }else{
            for(int z: tans){
                ans[tmp%200].push_back(z);
            }
            st[tmp%200].insert(tmp%200);
        }
    }
    cout << "No" << endl;
    return 0;
}