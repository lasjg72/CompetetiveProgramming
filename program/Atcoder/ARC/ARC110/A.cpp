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
    ll ans = 1;
    vector<int> a(n+1, 0);
    for(int i = 0; i <= n; i++){
        a[i] = i;
    }
    for(int i = 2; i <= n; i++){
        //cout << "a[i]: " << a[i] << endl;
        ans *= a[i];
        for(int j = i+i; j <= n; j += i){
            //cout << "j: " << j << endl;
            a[j] /= a[i];
        }
    }
    cout << ans + 1 << endl;
    return 0;
}
