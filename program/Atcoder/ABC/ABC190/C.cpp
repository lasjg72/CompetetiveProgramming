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
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for(int i = 0; i< m; i++){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    int k;
    cin >> k;
    vector<int> c(k), d(k);
    for(int i = 0; i < k; i++){
        cin >> c[i] >> d[i];
        c[i]--; d[i]--;
    }
    int ans = 0;
    for (int bit = 0; bit < (1<<k); bit++) {
        vector<int> dish(n, 0);
        int tmp = 0;
        for (int i = 0; i < k; i++) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                dish[d[i]]++;
            }else{
                dish[c[i]]++;
            }
        }

        for(int i = 0; i < m; i++){
            //cout << "dish[a[i]]: " << dish[a[i]] << "dish[b[i]]: " << dish[b[i]] << endl;
            if(dish[a[i]] > 0 && dish[b[i]] > 0) tmp++;
        }
        ans = max(ans, tmp);
        //cout << "ans: " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}