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
    int x;
    cin >> x;
    for(ll i = -1000; i <= 1000; i++){
        for(ll j = -1000; j <= 1000; j++){
            ll now = pow(i, 5)-pow(j, 5);
            if(now == x){
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    return 0;
}