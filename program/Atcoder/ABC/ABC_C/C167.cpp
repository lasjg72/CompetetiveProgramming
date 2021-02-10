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

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int n, m , x;
    cin >> n >> m >> x;
    vector<int> c(n), rikai(m, 0);
    vector<vector<int>> a(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        cin >> c[i];
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int ans = 1001001001;
    for(int bit = 0; bit < (1 << n); bit++){
        int tmp = 0;
        bool ok = false;
        
        for(int i = 0; i < m; i++) rikai[i] = 0;

        for(int i = 0; i < n; i++){
            if(bit & (1 << i)){
                tmp += c[i];
                for(int j =0 ; j < m; j++){
                    rikai[j] += a[i][j];
                }
            }
        }
        for(int j = 0; j < m; j++){
            if(rikai[j] < x){
                ok = true;
                break;
            }
        }
        if(ok) continue;
        ans = min(ans, tmp);
    }
    if(ans == 1001001001) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}