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
    ll k = 1;
    if(k == n) cout << 0 << endl;
    else{
        int num = 0;
        while(k <= n){
            k *= 2;
            num++;
        }
        cout << num-1 << endl;
    }
    return 0;
}