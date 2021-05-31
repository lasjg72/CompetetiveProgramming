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
    int h, w;
    cin >> h >> w;
    vector<vector<char>> s(h, vector<char>(w));
    vector<int> g[h*w+10];

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> s[i][j];        
        }
    }
    int num = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(i+1 < h && s[i][j] != s[i+1][j]){
                g[num].push_back(num+w);
                g[num+w].push_back(num);
            }
            else if(j+1 < w && s[i][j] != s[i][j+1]){
                g[num].push_back(num+1);
                g[num+1].push_back(num);
            }
            num++;
        }
    }
    //cout << "ko" << endl;
    vector<int> mark(num, 0);

    ll ans = 0;
    queue<int> q;
    vector<bool> bw(num, true);
    for(int i = 0; i < num; i++){
        int b = 0, w = 0;
        if(mark[i] != 0) continue;
        q.push(i);
        b++;
        bw[i] = false;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            mark[now] = 1;
            //cout << "now: " << now << endl;
            for(int t: g[now]){
                if(mark[t] != 0) continue;
                //cout << "t: " << t << endl;
                if(bw[now]) {
                    b++;
                    bw[t] = false;
                }
                else {
                    w++;
                    bw[t] = true;
                }
                q.push(t);
            }
        }
        //cout << "b: " << b << "w: " << w;
        ans += b * w;
    }
    cout << ans << endl;
    return 0;
}