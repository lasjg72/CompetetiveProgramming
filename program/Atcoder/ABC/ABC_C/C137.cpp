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
    int n;
    cin >> n;
    map<string, ll> ana;
    vector<string> s(n);
    for(int i = 0; i< n; i++){
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
        ana[s[i]]++;
    }
    ll ans = 0;
    for(int i = 0; i< n; i++){
        if(ana[s[i]] > 1){
            ll a = ana[s[i]];
            ans += a*(a-1)/2;
            ana[s[i]] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}