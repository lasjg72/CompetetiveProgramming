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
int p[1000005];
int num[1000005];

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> p;
    ll tmp = n;
    for(ll i = 2; i*i <= n; i++){
        int num = 0;
        while(tmp%i==0){
            tmp /= i;
            num++;
        }
        p.emplace_back(i, num);
    }
    if(tmp != 1) p.emplace_back(tmp, 1);
    int ans = 0;
    for(auto x : p){
        int num = x.second;
        int pos = 1;
        while(pos <= num){
            num -= pos;
            pos++;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}