#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <cassert>

using namespace std;
using ll = long long;

int main()
{
    ll t;
    cin >> t;
    for(ll i = 0; i < t; i++){
        ll n, s, k;
        cin >> n >> s >> k;
        ll tmp = n-s, ans = 0;
        unordered_map<ll, ll> a;
        ll loop = 0;
        while(1){
            loop++;
            if(tmp % k == 0){
                cout << tmp/k << endl;
                //cout << "loop: " << loop << endl;
                break;
            }else{
                if(a[tmp%k] >= 1){
                    cout << -1 << endl;
                    //cout << "loop: " << loop << endl;
                    break;
                }
                a[tmp%k]++;
                tmp += n;
            }
        }
    }
    return 0;
}