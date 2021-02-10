#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;
const ll mod = 1e18;

int main()
{
    ll a, b, c;
    ll k;
    cin >> a >> b >> c >> k;
    if(k % 2 == 1){
        if(abs(b-a) > mod) cout << "Unfair" << endl;
        else cout << b-a << endl;
    }else{
        if(abs(a-b) > mod) cout << "Unfair" << endl;
        else cout << a-b << endl;
    }
    return 0;
}
