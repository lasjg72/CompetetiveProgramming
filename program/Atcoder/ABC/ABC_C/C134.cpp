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
    vector<int> a(n);
    int mx = 0, m2 = 0;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
        mx = max(mx, a[i]);
    }
    for(int i = 0; i < n; i++){
        if(a[i] != mx) m2 = max(m2, a[i]);
    }
    for(int i = 0; i < n; i++){
        if(a[i] != mx) cout << mx << endl;
        else if(a[i] == mx && mp[mx] > 1) cout << mx << endl;
        else cout << m2 << endl;
    }
    return 0;
}