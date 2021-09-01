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
const int mod = 1e9+7;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    map<int, int> mp;
    ll pos = 1;
    for(int i = 0; i < 9; i++){
        cin >> mp[i+1];
        if(mp[i+1] > 0){
            for(int j = 1; j <= mp[i+1]; j++) pos *= j;
            a.push_back(i+1);
        }
    }
    ll ans = 0, tmp = 1;
    ll num = 1;
    for(int i = a.size()-1; i >= 1; i--) num *= i;
    for(int i = 0; i < n; i++){
        //cout << "----" << tmp << "----" << endl;
        for(int j : a){
            //cout << "j: " << j << " num[j]: " << mp[j] << endl;
            ans = ans+((((j*tmp)%mod)*num)%mod)*mp[j]%mod;
            ans %= mod;
        }
        tmp *= 10;
    }
    cout << ans << endl;
    return 0;
}