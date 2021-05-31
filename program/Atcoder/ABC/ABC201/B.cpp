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
    vector<pair<int, string>> a(n);
    for(int i = 0; i < n; i++){
        string s;
        int t;
        cin >> s >> t;
        a[i] = {t, s};
    }
    sort(a.begin(), a.end());
    cout << a[n-2].second << endl;
    return 0;
}