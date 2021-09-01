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
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int check = 0;
        for(int j : g[i]){
            if(j < i) check++;
        }
        if(check == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}