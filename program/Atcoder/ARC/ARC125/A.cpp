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
const ll INF = 1001001001;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> s(n), t(m);
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < m; i++) cin >> t[i];
    int dist = INF;
    for(int i = 1; i < n; i++){
        if(s[0] != s[i]){
            dist = min(dist, i);
            break;
        }
    }
    for(int i = n-1; i >= 1; i--){
        if(s[0] != s[i]){
            dist = min(dist, n-i);
            break;
        }
    }
    int num = s[0];
    int ans = 0;
    for(int i = 0; i < m; i++){
        if(num != t[i]){
            ans += dist+1;
            num = (num+1)%2;
            dist = 1;
        }
        else{
            ans++;
        }
    }
    if(ans >= INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}