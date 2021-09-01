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
    for(int i = 0; i < m; i++){
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
    for(int bit = 0; bit < (1<<k); bit++){
        vector<int> dish(n, 0);
        int tmp = 0;
        for(int i = 0; i < k; i++){
            if((bit>>i)&1){
                dish[c[i]]++;
            }else{
                dish[d[i]]++;
            }
        }
        for(int i = 0; i < m; i++){
            if(dish[a[i]] > 0 && dish[b[i]] > 0) tmp++;
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}