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

// set<ll> divine(ll n){
//     set<ll> d;
//     for(ll i = 1; i*i <= n; i++){
//         if(n % i == 0){
//             d.insert(i);
//             d.insert(n/i);
//         } 
//     }
//     return d;
// }

vector<ll> divine(ll n){
    vector<ll> d;
    for(ll i = 1; i*i <= n; i++){
        if(n % i == 0){
            d.push_back(i);
            if(sqrt(n) < n/i){
                d.push_back(n/i);
            }
        } 
    }
    sort(d.begin(), d.end());
    return d;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> d = divine(n);
    for(auto x : d){
        cout << x << endl;
    }
    return 0;
}