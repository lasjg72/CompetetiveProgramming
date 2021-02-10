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
    ll n, m;
    cin >> n >> m;
    if(n ==2 || m == 2){
        cout << 0 << endl;
        return 0;
    }
    if(n==1 || m == 1){
        if(n == 1 && m == 1){
            cout << 1 << endl;
            return 0;
        }else{
            int mx = max(n, m);
            cout << mx -2 << endl;
            return 0;
        }
    }
    cout << (n-2)*(m-2) << endl;
    return 0;
}