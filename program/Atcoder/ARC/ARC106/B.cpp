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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> b[i];
    }
    vector<ll> G[n];
    for(ll i = 0; i < m; i++){
        ll c, d;
        cin >> c >> d;
        c--; d--;
        G[c].push_back(d);
        G[d].push_back(c);
    }
    vector<ll> mark(n, 0);
    queue<ll> q;
    q.push(0);
    set<ll> used, noused;
    for(ll i= 0; i < n; i++){
        noused.insert(i);
    }
    while(noused.size() != 0){
        if(q.empty()){
            auto itr = noused.begin();
            q.push(*itr);
        }
        ll tmpa = 0, tmpb = 0;
        while(!q.empty()){
            ll now = q.front();
            q.pop();
            noused.erase(now);
            used.insert(now);
            tmpa += a[now];
            tmpb += b[now];
            mark[now] = 1;
            for(ll i = 0; i < G[now].size(); i++){
                ll p = G[now][i];
                if(mark[p] == 1) continue;
                q.push(p);
            }
        }
        if(tmpa != tmpb){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}