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

const int INF = 1001001001;

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c-1));
    vector<vector<int>> b(r-1, vector<int>(c));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c-1; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < r-1; i++){
        for(int j = 0; j < c; j++){
            cin >> b[i][j];
        }
    }
    vector<int> dist(r*c*2, INF);
    priority_queue<P, vector<P>, greater<P>> q;
    // update cost of dist about destination
    auto update = [&](int i, int j, int k, int cost){
        int now = i*c*2+j*2+k;
        if(dist[now] <= cost) return;
        dist[now] = cost;
        q.emplace(cost, now);
    };
    //update(0, 0, 0, 0);
    q.emplace(0, 0);
    dist[0] = 0;
    while(!q.empty()){
        P p = q.top(); q.pop();
        int v = p.second;
        int x = p.first;
        if(dist[v] != x) continue;
        int i = v/(2*c);
        int j = (v/2)%c;
        int k = v%2;
        if(k == 0){ //not cost 1+i
            if(j+1 < c) update(i, j+1, k, x+a[i][j]);
            if(j-1 >= 0) update(i, j-1, k, x+a[i][j-1]);
            if(i+1 < r) update(i+1, j, k, x+b[i][j]);
            update(i, j, k+1, x+1);
        }else{
            if(i-1 >= 0) update(i-1, j, k, x+1);
            update(i, j, k-1, x);
        }
    }
    cout << dist[2*r*c-2] << endl;
    return 0;
}