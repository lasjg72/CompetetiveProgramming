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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> t(m+1);
    priority_queue<int> p;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(a > m) continue;
        t[a].push_back(b);
    }
    ll ans = 0;
    for(int i = 1; i <= m; i++){
        for(int b : t[i]){
            p.push(b);
            //cout << "b: " << b << endl;
        }
        if(p.empty()) continue;
        int now = p.top(); p.pop();
        //cout << "now: " << now << endl;
        ans += now;
    }
    cout << ans << endl;
    return 0;
}