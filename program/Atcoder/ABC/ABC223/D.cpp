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
    vector<vector<int>> g(n);
    vector<int> in(n, 0);
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        g[a[i]].push_back(b[i]);
        in[b[i]]++;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < n; i++) if(in[i] == 0) q.push(i);
    vector<int> ans;
    while(!q.empty()){
        int now = q.top(); q.pop();
        for(int to : g[now]){
            in[to]--;
            if(in[to] == 0) q.push(to);
        }
        ans.push_back(now);
    }
    if(ans.size() == n){
        for(int i : ans){
            cout << i+1 << endl;
        }
    }else{
        cout << -1 << endl;
    }
    return 0;
}