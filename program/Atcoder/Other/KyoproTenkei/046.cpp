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
    vector<int> a(n), b(n), c(n);
    map<int, ll> mpa, mpb, mpc;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mpa[a[i]%46]++;
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        mpb[b[i]%46]++;
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
        mpc[c[i]%46]++;
    }
    ll ans = 0;
    for(int i = 0; i < 46; i++){
        for(int j = 0; j < 46; j++){
            for(int k = 0; k < 46; k++){
                if((i+j+k)%46 == 0){
                    ans += mpa[i]*mpb[j]*mpc[k];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}