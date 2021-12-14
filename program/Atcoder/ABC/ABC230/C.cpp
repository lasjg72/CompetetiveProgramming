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
    ll n, a, b, p, q, r, s;
    cin >> n >> a >> b >> p >> q >> r >> s;
    for(ll i = p; i <= q; i++){
        for(ll j = r; j <= s; j++){
            if(i+j == a+b || i-a == j-b || -(i-a) == j-b){
                cout << "#";
            }else cout << ".";
        }
        cout << endl;
    }
    return 0;
}