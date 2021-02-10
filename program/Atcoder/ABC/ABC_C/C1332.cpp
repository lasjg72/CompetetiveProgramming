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
    ll l, r;
    cin >> l >> r;
    int rep = r-l;
    rep = min(rep, 673);
    ll ans = 2018;
    for(int i = 0; i < rep; i++){
        for(int j = l + i + 1; j < l+1+rep; j++){
            ans = min(ans, ((l+i)*j)%2019);
        }
    }
    cout << ans << endl;
    return 0;
}