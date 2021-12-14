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
    int n;
    cin >> n;
    vector<pair<int, int>> p;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        p.push_back({a, 1});
        p.push_back({a+b, -1});
    }
    sort(p.begin(), p.end());
    int cnt = 0, t = 0;
    vector<ll> ans(n+1);
    for(pair<int, int> now : p){
        ans[cnt] += now.first-t;
        cnt += now.second;
        t = now.first;
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}