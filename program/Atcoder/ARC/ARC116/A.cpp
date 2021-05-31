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
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n%2){
            cout << "Odd" << endl;
            continue;
        }else{
            if(n%4 == 0) cout << "Even" << endl;
            else cout << "Same" << endl;
        }
    }
    return 0;
}
