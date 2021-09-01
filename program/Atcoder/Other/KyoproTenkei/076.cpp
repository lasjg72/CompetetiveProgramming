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
    vector<ll> a(2*n);
    ll tot = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        tot += a[i];
        a[i+n] = a[i];
    }
    int l = 0, r = 0;
    ll tmp = 0;
    while(l < n){
        
        if(tmp == tot/10){
            cout << "Yes" << endl;
            return 0;
        }

    }
    cout << "No" << endl;
    return 0;
}