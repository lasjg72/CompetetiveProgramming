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
    ll a, b;
    cin >> a >> b;
    ll tot = 0;
    if(a >= b){
        for(int i = 1; i <= a; i++){
            cout << i << " ";
            tot += i;
        }
        for(int i = 1; i < b; i++){
            cout << -i << " ";
            tot -= i;
        }
        cout << -tot << endl;
    }else{
        for(int i = 1; i <= b; i++){
            cout << -i << " ";
            tot -= i;
        }
        for(int i = 1; i < a; i++){
            cout << i << " ";
            tot += i;
        }
        cout << -tot << endl;
    }
    return 0;
}