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

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

ll gcd(ll a, ll b){
    if(a%b == 0) return b;

    return gcd(b, a%b);
}

int main()
{
    ll a, b;
    cin >> a >> b;
    ll g = gcd(a, b);
    if(g == 1){
        cout << "Odd" << endl;
        return 0;
    }
    for(ll i = 2; i*i <= g; i++){
        if(i * i == g){
            cout << "Odd" << endl;
            return 0;
        }
    }
    cout << "Even" << endl;
    return 0;
}