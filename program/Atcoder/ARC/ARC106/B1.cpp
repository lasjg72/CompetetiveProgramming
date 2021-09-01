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

vector<vector<int>> g;
vector<bool> used;
vector<int> a, b;
ll to1, to2;

void calc(int x, int p){
    for(int to : g[x]){
        if(to == p) continue;
        if(used[to]) continue;
        used[to] = true;
        to1 += a[to];
        to2 += b[to];
        calc(to, x);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n, false);
    a.resize(n);
    b.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < m; i++){
        int c, d;
        cin >> c >> d;
        c--; d--;
        g[c].push_back(d);
        g[d].push_back(c);
    }
    for(int i = 0; i < n; i++){
        if(used[i]) continue;
        used[i] = true;
        to1 = a[i];
        to2 = b[i];
        calc(i, -1);
        if(to1 != to2){
            cout << "No" << endl;
            return 0;
        }
        to1 = 0;
        to2 = 0;
    }
    cout << "Yes" << endl;
    return 0;
}