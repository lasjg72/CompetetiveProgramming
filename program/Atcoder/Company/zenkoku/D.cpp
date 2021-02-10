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
    vector<int> G[n];
    vector<int> deg(n, 0);
    for(int i = 0; i < n-1+m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        deg[b]++;
    }
    queue<int> que;
    for(int i = 0; i < n; i++){
        if(deg[i] == 0){
            que.push(i);
        }
    }
    vector<int> order;
    vector<int> ans(n, 0);
    while(!que.empty()){
        int now = que.front(); que.pop();
        order.push_back(now);

        for(auto v: G[now]){
            deg[v]--;
            if(deg[v] == 0) {
                que.push(v);
                ans[v] = now+1;
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     cout << order[i] << endl;
    // }

    // cout << "---" << endl;

    

    // for(int i = 0; i < n-1; i++){
    //     int now = order[i];
    //     int mi = -1;
    //     for(auto v : G[now]){
    //         mi = max(v, mi);
    //     }
    //     ans[now] = mi + 1;
    // }
    // ans[order[n-1]] = 0;
    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}