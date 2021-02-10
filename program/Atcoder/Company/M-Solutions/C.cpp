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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i = 0; i< n; i++){
        cin >> a[i];
    }
    for(ll i = 0; i< n; i++){
        if(i >= k){
            if(a[i-k] < a[i]) cout << "Yes" << endl;
            else cout << "No" << endl;
            //cout << "pre" << pre << endl;
            //cout << "score" << score << endl;   
        }
    }
    return 0;
}