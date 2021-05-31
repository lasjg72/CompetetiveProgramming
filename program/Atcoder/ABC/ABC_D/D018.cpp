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
using P = pair<int, int>;

int main()
{
    int n, m, p, q, r;
    cin >> n >> m >> p >> q >> r;
    vector<int> x(r), y(r), z(r);
    for(int i = 0; i < r; i++){
        cin >> x[i] >> y[i] >> z[i];
        x[i]--;
        y[i]--;
    }
    int ans = 0;
    for(int bit = 0; bit < (1<<n); bit++){
        if(__builtin_popcount(bit) != p) continue;
        int now = 0;
        vector<int> cho(m, 0);
        for(int i = 0; i < n; i++){
            if(bit>>i&1){
                for(int j = 0; j < r; j++){
                    if(x[j] == i){
                        cho[y[j]] += z[j];
                    }
                }
            }
        }
        sort(cho.rbegin(), cho.rend());
        set<int> st;
        for(int j = 0; j < q; j++){
            now += cho[j];
        }
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}