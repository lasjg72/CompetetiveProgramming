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
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++){
        int b;
        cin >> b;
        a[i] = {b, i+1};
    }
    sort(a.rbegin(), a.rend());
    //cout << a[1].first << endl;
    cout << a[1].second << endl;
    return 0;
}