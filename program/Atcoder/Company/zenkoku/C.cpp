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
    vector<ll> a(n), b(n), used(n, 0); 
    vector<pair<ll, ll>> t(n), ao(n); 
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        t[i].first = b[i]+a[i];
        t[i].second = i;
        ao[i].first = b[i]+a[i];
        ao[i].second = i;
    }
    sort(t.rbegin(), t.rend());
    sort(ao.rbegin(), ao.rend());
    ll ans = 0;
    ll j = 0, k = 0;
    for(int i = 0; i < n; i++){
        if(i%2==0){
            while(used[t[j].second] == 1) j++;
            int num = t[j].second;
            ans += a[num];
            used[num] = 1;
        }else{
            while(used[ao[k].second] == 1) k++;
            int num = ao[k].second;
            ans -= b[num];
            used[num] = 1;
        }
        //cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
