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
    vector<ll> a(n), b(n);
    ll atot = 0, btot = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        atot += a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        btot += b[i];
    }
    ll num1 = btot - atot;
    for(int i = 0; i < n; i++){
        if(a[i] < b[i]){
            num1 -= ceil(((long double)b[i]-(long double)a[i])/(long double)2);
        }else if(a[i] > b[i]){
            //num1 -= a[i]-b[i];
        }
    }
    if(num1 >= 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}