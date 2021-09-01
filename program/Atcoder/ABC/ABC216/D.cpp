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
    vector<queue<int>> a(m);
    for(int i = 0; i < m; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int b;
            cin >> b;
            a[i].push(b);
        }
    }
    vector<vector<int>> num(n+1);
    map<int, int> mp;
    queue<P> q;
    for(int i = 0; i < m; i++){
        int now = a[i].front();
        mp[now]++;
        num[now].push_back(i);
        if(mp[now] > 1){
            q.push({num[now][0], num[now][1]});
        }
    }
    while(!q.empty()){
        P p = q.front(); q.pop();
        // cout << "---" << endl;
        // cout << p.first << " " << p.second << endl;

        a[p.first].pop();
        a[p.second].pop();
        if(a[p.first].size() > 0){
            int now = a[p.first].front();
            //cout << "now: " << now << endl;
            mp[now]++;
            num[now].push_back(p.first);
            if(mp[now] > 1){
                q.push({num[now][0], num[now][1]});
            }
        }
        if(a[p.second].size() > 0){
            int now = a[p.second].front();
            //cout << "now: " << now << endl;
            mp[now]++;
            num[now].push_back(p.second);
            if(mp[now] > 1){
                q.push({num[now][0], num[now][1]});
            }
        }
    }
    for(int i = 0; i < m; i++){
        if(a[i].size() > 0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}