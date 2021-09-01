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

const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int h, w;
vector<string> s, t;
int ans;
int dist[505][505];

void dfs(int i, int j, int num){
    if(i == h-1 && j == w-1){
        ans = min(ans, num);
        return;
    }
    deque<P> q;
    q.emplace_back(i, j);
    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        int d = num;
        q.pop_front();
        if (dist[i][j] <= d) continue;
        for(int v = 0; v < 4; v++) {
            int ni = i+di[v], nj = j+dj[v];
            if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
            if (s[ni][nj] == '#'){
                s[ni][nj] = '.';
                dist[ni][nj] = min(dist[ni][nj], num+1);
                if(ni+1 < h){
                    if(nj+1 < w){
                        s[ni+1][nj+1] = '.';
                        s[ni][nj+1] = '.';
                        s[ni+1][nj] = '.';
                        dfs(ni, nj, num+1);
                        s[ni+1][nj+1] = t[ni+1][nj+1];
                        s[ni][nj+1] = t[ni][nj+1];
                        s[ni+1][nj] = t[ni+1][nj];
                    }
                    if(nj-1 >= 0){
                        s[ni+1][nj-1] = '.';
                        s[ni][nj-1] = '.';
                        s[ni+1][nj] = '.';
                        dfs(ni, nj, num+1);
                        s[ni+1][nj-1] = t[ni+1][nj-1];
                        s[ni][nj-1] = t[ni][nj-1];
                        s[ni+1][nj] = t[ni+1][nj];
                    }
                }
                if(ni-1 >= 0){
                    if(nj+1 < w){
                        s[ni-1][nj+1] = '.';
                        s[ni][nj+1] = '.';
                        s[ni-1][nj] = '.';
                        dfs(ni, nj, num+1);
                        s[ni-1][nj+1] = t[ni-1][nj+1];
                        s[ni][nj+1] = t[ni][nj+1];
                        s[ni-1][nj] = t[ni-1][nj];
                    }
                    if(nj-1 >= 0){
                        s[ni-1][nj-1] = '.';
                        s[ni][nj-1] = '.';
                        s[ni-1][nj] = '.';
                        dfs(ni, nj, num+1);
                        s[ni-1][nj-1] = t[ni-1][nj-1];
                        s[ni][nj-1] = t[ni][nj-1];
                        s[ni-1][nj] = t[ni-1][nj];
                    }
                }
            }else{
            if (dist[ni][nj] <= d) continue;
            dist[ni][nj] = d;
            q.emplace_front(ni,nj);
            }
        }
        // for (int ei = -2; ei <= 2; ++ei) {
        //     for (int ej = -2; ej <= 2; ++ej) {
        //         int ni = i+ei, nj = j+ej;
        //         if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        //         if (s[ni][nj] == '#') continue;
        //         if (dist[ni][nj] <= d+1) continue;
        //         dist[ni][nj] = d+1;
        //         q.emplace_back(ni,nj);
        //     }
        // }
    }
}
 
int main() {
  cin >> h >> w;
  s.resize(h);
  t.resize(h);
  for(int i = 0; i < h; i++) cin >> s[i];
  t = s;
  const int INF = 1e9;
  for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++) dist[i][j] = INF;
  }
  dfs(0, 0, 0);
  cout << ans << endl;
  return 0;
}