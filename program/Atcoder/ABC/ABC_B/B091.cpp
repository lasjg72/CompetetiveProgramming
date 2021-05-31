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
    vector<string> s(n);
    map<string, int> tasu;
    map<string, int> hiku;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        tasu[s[i]]++;
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        string t;
        cin >> t;
        hiku[t]++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, tasu[s[i]]-hiku[s[i]]);
    }
    cout << ans << endl;
    return 0;
}