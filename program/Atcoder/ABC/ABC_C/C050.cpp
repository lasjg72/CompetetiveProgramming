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
const int mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> num;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        num[a[i]]++;
    }
    for(int i = 1; i < n; i++){
        if(num[i]%2){
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = 1;
    for(int i = 0; i < n/2; i++){
        ans = (ans*2)%mod;
    }
    cout << ans << endl;
    return 0;
}