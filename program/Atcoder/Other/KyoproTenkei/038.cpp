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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main()
{
    ll a, b;
    cin >> a >> b;
    ll g = gcd(a, b);
    if(a/g > (ll)1e18/b){
        cout << "Large" << endl;
    }else{
        cout << a/g*b << endl;
    }
    return 0;
}