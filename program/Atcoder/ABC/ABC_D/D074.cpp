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
const int INF = 1001001001;

int main()
{
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j || j == k || i==k || a[i][j] == INF || a[i][k] == INF || a[k][j] == INF) continue;
                if(a[i][j] > a[i][k]+a[k][j]){
                    cout << -1 << endl;
                    return 0;
                }else if(a[i][j] == a[i][k]+a[k][j]){
                    a[i][j] = INF;
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(a[i][j] == INF) continue;
            ans += a[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}