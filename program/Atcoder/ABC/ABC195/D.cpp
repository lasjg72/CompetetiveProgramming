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
    int n, m, q;
    cin >> n >> m >> q;
    vector<P> vw(n);
    vector<int> x(m);
    for(int i = 0; i < n; i++){
        cin >> vw[i].second >> vw[i].first;
    }
    for(int i = 0; i < m; i++){
        cin >> x[i];
    }
    sort(vw.rbegin(), vw.rend());
    while(q--){
        int l, r;
        cin >> l >> r;
        l--; r--;
        int ans = 0;
        vector<bool> used(m, false);
        for(int i = 0; i < m; i++){
            if(i >= l && i <= r) used[i] = true;
        }
        for(int i = 0; i < n; i++){
            int tmp = 1001001001;
            int num = -1;
            int pos;
            for(int j = 0; j < m; j++){
                if(used[j]) continue;
                if(vw[i].second <= x[j] && tmp > x[j]){
                    tmp = x[j];
                    num = j;
                    pos = i;
                }
            }
            if(tmp == 1001001001) continue;
            used[num] = true;
            ans += vw[pos].first;
        }
        cout << ans << endl;
    }
    return 0;
}