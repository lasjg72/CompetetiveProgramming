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
    int n , m;
    cin >> n >> m;
    vector<int> h(n), w(m);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    for(int i = 0; i < m; i++){
        cin >> w[i];
    }
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        auto itr1 = lower_bound(w.begin(), w.end(), h[i]);
        auto itr2 = lower_bound(w.begin(), w.end(), h[i]-(*itr1-h[i]));
        int tmp1 = min(abs(h[i]-*itr1), abs(h[i]-*itr2));
        
    }
    return 0;
}