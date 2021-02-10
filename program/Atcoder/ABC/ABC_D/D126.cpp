#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;
int n;
vector<int> ans;
//vector<int> edge[];

// void dfs(){
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < edge[i].size(); j++){
//             //cout << "i, j:" << i << " " << j << endl;
//             int v = edge[i][j];
//             if(G[i][v] != 0 && G[i][v] % 2 == 0){
//                 ans[i] = 0;
//                 ans[v] = 0;
//             }
//         }
//     }
// }

int main()
{
    cin >> n;
    
    ans.resize(n, -1);
    vector<int> to[n], cost[n];

    for(int i = 0; i < n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        to[u].push_back(v);
        cost[u].push_back(w);
        to[v].push_back(u);
        cost[v].push_back(w);
    }
    int root = 0;
    queue<int> q;
    ans[root] = 0;
    q.push(root);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0; i < to[now].size(); i++){
            int v = to[now][i];
            int c = cost[now][i];
            if(ans[v] != -1) continue;
            ans[v] = (ans[now] + c) % 2;
            q.push(v);
        }
    }

    for(int i = 0; i< n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}