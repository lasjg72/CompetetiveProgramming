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
    vector<ll> a(n), b(n), c(n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    ll amx = a[0], bmx = b[0];
    c[0] = a[0] * b[0];
    for(int i = 1; i < n; i++){
        if(amx < a[i]){
            amx = max(amx, a[i]);
            c[i] = max(c[i-1], amx*b[i]);
        }
        if(bmx < b[i]){
            bmx = max(bmx, b[i]);
            c[i] = max(c[i-1], amx*bmx);
        }
        c[i] = max(c[i-1], amx*b[i]);
    }
    for(int i = 0; i < n; i++){
        cout << c[i] << endl;
    }
    return 0;
}