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

struct edge{
    int from;
    int to;
    int co;
};

int main()
{
   int n;
   cin >> n;
   vector<vector<int>> g(n);
   vector<ll> cost(n, 1001001001);
   vector<bool> stamp(n, false);
   for(int i = 0; i < n-1; i++){
       int a, b;
       cin >> a >> b;
       a--; b--;
       g[a].push_back(b);
       g[b].push_back(a);
   }
   int si = 0;
   int tar = 0;
   for(int i = 0; i < n; i++){
       if(si <= g[i].size()){
           si = g[i].size();
           tar = i;
       }
   }
   if(si <= 2){
       cout << "Yes" << endl;
       return 0;
   }
   //cout << tar << endl;
   queue<int> q;
   q.push(tar);
   cost[tar] = 0;
   vector<ll> ans;
   stamp[tar] = true;
   while(!q.empty()){
       int u = q.front(); q.pop();
       for(int v: g[u]){
           if(stamp[v] == true) continue;
           else stamp[v] = true;
            cost[v] = cost[u]+1;
           if(g[v].size() == 1) ans.push_back(cost[v]);
           else q.push(v);
       }
   }
   ll tmp = ans[0];
   for(ll now : ans){
       //cout << now << endl;
       if(tmp != now){
           cout << "No" << endl;
           return 0;
       }
   }
   cout << "Yes" << endl;
   return 0;
}