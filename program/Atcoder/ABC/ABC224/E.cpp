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
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> r(n), c(n);
    vector<int> a(n);
    vector<int> ans(n);
    vector<P> p(n);
    for(int i = 0; i < n; i++){
        cin >> r[i] >> c[i] >> a[i];
        p[i] = {a[i], i};
    }
    sort(p.rbegin(), p.rend());
    
    vector<P> yoko(h, {INF, -1}), tate(w, {INF, -1});
    //vector<vector<P>> num(h, vector<P>(w, {INF, -1}));
    for(int i = 0; i < n; i++){
        //cout << "---" << endl;
        P now = p[i];
        int x = c[now.second];
        int y = r[now.second];
        x--; y--;
        //cout << "x: " << x << "y: " << y << endl; 
        //cout << "now: " << now.first << endl;
        if(yoko[y].first > tate[x].first){
            if(yoko[y].first > now.first){
                //cout << "yoko: " << yoko[y].first << endl;
                yoko[y].first = now.first;
                yoko[y].second++;
                ans[now.second] = max(ans[now.second], yoko[y].second);
            }
            if(tate[x].first > now.first){
                //cout << "tate: " << tate[x].first << endl;
                tate[x].first = now.first;
                tate[x].second++;
                ans[now.second] = max(ans[now.second], tate[x].second);
                //cout << "ans: " << ans[now.second] << endl;
            }
        }else{
            if(tate[x].first > now.first){
                //cout << "tate: " << tate[x].first << endl;
                tate[x].first = now.first;
                tate[x].second++;
                ans[now.second] = max(ans[now.second], tate[x].second);
                //cout << "ans: " << ans[now.second] << endl;
            }
            if(yoko[y].first > now.first){
                //cout << "yoko: " << yoko[y].first << endl;
                yoko[y].first = now.first;
                yoko[y].second++;
                ans[now.second] = max(ans[now.second], yoko[y].second);
            }
        
        }
        tate[x].second = max(tate[x].second, yoko[y].second);
        yoko[y].second = max(tate[x].second, yoko[y].second);
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}