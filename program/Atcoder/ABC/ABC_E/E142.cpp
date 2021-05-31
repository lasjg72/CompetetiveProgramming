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
const int INF = 1001001001;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<P> key;
    vector<int> dp(1<<n, INF);
    dp[0] = 0;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        int s = 0;
        for(int j = 0; j < b; j++){
            int c;
            cin >> c;
            c--;
            s |= 1<<c;
        }
        key.emplace_back(s, a);
    }
    for(int s = 0; s < (1<<n); s++){
        for(int i = 0; i < m; i++){
            int now = s|key[i].first;
            dp[now] = min(dp[now], dp[s]+key[i].second);
        }
    }
    if(dp[(1<<n)-1] == INF) cout << -1 << endl;
    else cout << dp[(1<<n)-1] << endl;
    return 0;
}