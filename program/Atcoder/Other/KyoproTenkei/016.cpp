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
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    int ans = 1001001001;
    for(int i = 0; i <= 9999; i++){
        for(int j = 0; j <= 9999; j++){
            ll tot = a*i+b*j;
            if(tot > n) continue;
            int nc = 0;
            if((n-tot)%c == 0){
                nc = (n-tot)/c;
                ans = min(ans, i+j+nc);
            }
        }
    }
    cout << ans << endl;
    return 0;
}