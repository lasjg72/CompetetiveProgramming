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
    ll x;
    cin >> x;
    if(x < 7){
        cout << 1 << endl;
    }else if(x < 11){
        cout << 2 << endl;
    }else{
        if(x % 11 == 0){
            cout << x/11 * 2 << endl;
        }else if(x % 11 < 7){
            cout << x/11 * 2 + 1 << endl;
        }else{
            cout << x/11 * 2 + 2 << endl;
        }
    }
    return 0;
}