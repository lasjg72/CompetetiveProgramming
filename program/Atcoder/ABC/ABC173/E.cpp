#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> pl, ne;
    ll x=0, y = 0;
    for(ll i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        if(tmp < 0) {
            ne.push_back(tmp);
            y++;
        }else{
            pl.push_back(tmp);
            x++;
        }
    }
    sort(pl.rbegin(), pl.rend());
    sort(ne.begin(), ne.end());
    ll ans = 1; 
    x = 0, y = 0;
    for(int i = 0; i < k; i ++){
        if(pl.size() > 0  && ne.size() > 0 && abs(pl[x]) > abs(ne[y]) && x < pl.size()){
            ans *= pl[x];
            x++;
        }else if(pl.size() > 0  && ne.size() > 0 && abs(pl[x]) <= abs(ne[y]) && y < ne.size()){
            ans *= ne[y];
            y++;
        }else if(pl.size() > 0){
            ans *= pl[x];
            x++;
        }else if(ne.size() > 0){
            ans *= ne[y];
            y++;
            cout << ans << endl;
        }
    }
    if(ans >= 0){
        cout << ans%mod << endl;
        return 0;
    }else{
        ll tmp1 = 0, tmp2 = 0, mx;
        if(x != pl.size()){
            cout << 1 << endl;
            tmp1 = ans / ne[y-1] * pl[x];
        }
        else if(y != ne.size()){
            cout << 2 << endl;
            tmp2 = ans / pl[x-1] * ne[y];
        }else if(ne.size() > 0){ //入力列がすべて負でkが奇数
            cout << 3 << endl;
            cout << ans%mod << endl;
            return 0;
        }
        mx = max(tmp1, tmp2);
        cout << mx%mod << endl;
        return 0;
    }
    return 0;
}