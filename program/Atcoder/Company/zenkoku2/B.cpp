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
const ll mod = 998244353;
int main()
{
    int n;
    cin >> n;
    vector<int> d(n);
    int mx = 0;
    map<int, int> num;
    for(int i = 0; i < n; i++){
        cin >> d[i];
        mx = max(mx, d[i]);
        num[d[i]]++;
    }
    if(d[0] != 0){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    for(int i = 1; i <= mx; i++){
        ll now = num[i-1];
        if(now == 0){
            cout << 0 << endl;
            return 0;
        }
        //cout << now << endl;
        for(int j = 0; j < num[i]; j++){
            ans = (ans * now) % mod;
            //cout << "ans: " << ans << endl;
        }
    }
    if(num[0] > 1 || num[0] == 0){
        cout << 0 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}