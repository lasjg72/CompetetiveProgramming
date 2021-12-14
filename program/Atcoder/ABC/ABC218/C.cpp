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
vector<string> s, t;

int main()
{
    int n;
    cin >> n;
    s.resize(n);
    t.resize(n);
    vector<P> p, q;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) cin >> t[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j] == '#') p.push_back({i, j});
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(t[i][j] == '#') q.push_back({i, j});
        }
    }
    P now = p[0];
    for(P tmp : q){
        int x = tmp.first-now.first;
        int y = tmp.second-now.second;
        vector<P> p2;
        for(P tmp2 : p){
            if(tmp2 == now) continue;
            p2.push_back({tmp2.first+x, tmp2.second+y});
        }
        int tox[4] = {1, -1, -1, 1};
        int toy[4] = {1, 1, -1, -1};
        int nowx = now.first + x;
        int nowy = now.second + y;
        for(int i = 0; i < 4; i++){
            for(P tmp2 : p){
                int tx = 
            }
        }
    }
    return 0;
}