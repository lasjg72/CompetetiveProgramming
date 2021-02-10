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
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    ll tmp = 2 * (n+1);
    ll x = sqrt(tmp);
    //cout << "x: " << x << endl;
    while(x * (x + 1) < tmp){
        x++;
    }
    if(x * (x + 1) == tmp){

    }else{
        x--;
    }
    cout << n+1-x << endl;
    return 0;
}