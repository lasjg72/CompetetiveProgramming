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
    for(int i = 0; i < n; i++) cin >> a[i];
    ll res = 1001001001001001001;
    for(int bit = 0; bit < (1<<(n-1)); bit++){
        //cout << "---" << endl;
        vector<ll> ans;
        ll tmp = 0;
        for(int i = 0; i < n-1; i++){
            tmp |= a[i];
            if((bit>>i)&1){
                ans.push_back(tmp);
                //cout << "add tmp: " << tmp << endl;
                tmp = 0;
            }
        }
        tmp |= a[n-1];
        if(tmp != 0) {
            ans.push_back(tmp);
            //cout << "add tmp: " << tmp << endl;
        }
        ll now = 0;
        for(ll t : ans){
            now ^= t;
        }
        res = min(res, now);
    }
    cout << res << endl;
    return 0;
}