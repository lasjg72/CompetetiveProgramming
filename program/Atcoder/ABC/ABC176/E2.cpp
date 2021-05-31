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

struct edge{
    int to;
    int co;
    edge(int to, int co):to(to), co(co){};
};

int main()
{
    int h, w;
    cin >> h >> w;
    int ch, cw;
    cin >> ch >> cw;
    ch--; cw--;
    int dh, dw;
    cin >> dh >> dw;
    dh--; dw--;
    vector<vector<char>> s(h, vector<char>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> s[i][j];
        }
    }
    vector<vector<edge>> g(h*w);
    vector<int> dist(h*w, INF);
    vector<bool> used(h*w);

    int x[4] = {0, 1, 0, -1};
    int y[4] = {1, 0, -1, 0};
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int now = i*w+j;
            if(s[i][j] == '#') continue;
            for(int num = 0; num < 4; num++){
                int nx = i+x[num];
                int ny = j+y[num];
                int now2 = nx*w+ny;
                if(nx >= 0 && nx < h && ny >= 0 && ny < w && s[nx][ny] == '.'){
                    g[now].emplace_back(now2, 0);
                }
            }
        }
    }


    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int now = i*w+j;
            if(s[i][j] == '#') continue;
            for(int ni = -2; ni < 3; ni++){
                for(int nj = -2; nj < 3; nj++){
                    int nx = i+ni;
                    int ny = j+nj;
                    if(nx < 0 || nx > h-1 || ny < 0 || ny > w-1) continue;
                    if(s[nx][ny] == '#') continue;
                    int nv = nx*w+ny;
                    g[now].emplace_back(nv, 1);
                }
            }
        }
    }

    // for(int i = 0; i < h; i++){
    //     for(int j = 0; j < w; j++){
    //         for(edge e:g[i*w+j]){
    //             cout << "edge";
    //             cout << " e.to: " << e.to << " " << e.co;
    //         }
    //         cout << endl;
    //     }
    // }

    priority_queue<P, vector<P>, greater<P>> q;
    q.emplace(ch*w+cw, 0);
    int tar = ch*w+cw;
    dist[tar] = 0;
    while(!q.empty()){
        P p = q.top(); q.pop();
        int nv = p.first;
        int nc = p.second;
        //cout << "nv: " << nv << " nc: " << nc << endl;
        if(dist[nv] != nc) continue;
        for(edge e : g[nv]){
            if(dist[nv]+e.co >= dist[e.to]) continue;
            dist[e.to] = dist[nv]+e.co;
            q.emplace(e.to, dist[e.to]);
        }
    }
    if(dist[dh*w+dw] == INF) cout << -1 << endl;
    else cout << dist[dh*w+dw] << endl;
    return 0;
}