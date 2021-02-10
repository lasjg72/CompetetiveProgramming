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
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll now = a[i];
        ll tmpmax = 0;
        ll tmp = 0;
        for(int j = 0; j < n; j++){
            if(i != j){
                if(a[j] >= now){
                    tmp += now;
                }else{
                    tmpmax = max(tmpmax, tmp);
                    tmp = 0;
                }
            }else{
                tmp += now;
            }
        }
        tmpmax = max(tmpmax, tmp);
        ans = max(ans, tmpmax);
    }
    cout << ans << endl;
    return 0;
}