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
    string s, t;
    cin >> s >> t;
    vector<vector<int>> pos(26);
    int n = (int)s.size();
    int m = (int)t.size();
    for(int i = 0; i < n; i++) pos[s[i]-'a'].push_back(i);
    for(int i = 0; i < n; i++) pos[s[i]-'a'].push_back(i+n);
    int p = 0;
    ll ans = 0;
    for(int i = 0; i < m; i++){
        char c = t[i];
        if(pos[c-'a'].size() == 0){
            cout << -1 << endl;
            return 0;
        }
        p = *lower_bound(pos[c-'a'].begin(), pos[c-'a'].end(), p)+1;
        if(p >= n){
            p -= n;
            ans += n;
        }
    }
    ans += p;
    cout << ans << endl;
    return 0;
}