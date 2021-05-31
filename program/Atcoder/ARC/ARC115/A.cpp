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
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<ll> num(n, 0);
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int j = 0;j < m; j++){
            if(s[i][j] == '0') num[i]++;
        }
    }
    ll odd = 0, ev = 0;
    for(int i = 0; i < n; i++){
        if(num[i]%2) odd++;
        else ev++;
    }
    ll ans = 0;
    ans = odd*ev;
    cout << ans << endl;
    return 0;
}