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

int main()
{
    ll a, b, k;
    cin >> a >> b >> k;
    if(a >= k){
        a = a-k;
    }else if(a < k){
        k = k-a;
        a = 0;
        if(b >= k){
            b = b-k;
        }else if(b < k){
            b = 0;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}