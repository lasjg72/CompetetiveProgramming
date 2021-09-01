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
    int k, a, b;
    cin >> k >> a >> b;
    if(b-a <= 2 || k <= a) cout << k+1 << endl;
    else{
        ll ans = a;
        k -= (a-1);
        if(k%2 == 0){
            int num = k/2;
            ans += (ll)(b-a)*num;
        }else{
            int num = (k-1)/2;
            ans += (ll)(b-a)*num;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}