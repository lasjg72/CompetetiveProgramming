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
int n, a, b, c;
int ans=1001001001;
vector<int> t;

void calc(vector<int> v){
    int at=0, bt=0, ct=0, tmp = 0;
    bool ab = false, bb = false, cb = false;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == 0){
            continue;
        }else if(v[i] == 1){
            at += t[i];
            tmp += 10;
            ab = true;
        }else if(v[i] == 2){
            bt += t[i];
            tmp += 10;
            bb = true;
        }else if(v[i] == 3){
            ct += t[i];
            tmp += 10;
            cb = true;
        }
    }
    if(!ab || !bb || !cb){
        return;
    }
    tmp += abs(at-a);
    tmp += abs(bt-b);
    tmp += abs(ct-c);
    tmp -= 30;
    ans = min(tmp, ans);
}

void dfs(int depth, vector<int> &v){
    if(depth == n){
        calc(v);
        return ;
    }
    for(int i = 0; i< 4; i++){
        v[depth] = i;
        dfs(depth + 1, v);
    }
}

int main()
{
    cin >> n >> a >> b >> c;
    vector<int> v(n, 0);
    t.resize(n);
    for(int i = 0; i< n; i++){
        cin >> t[i];
    }
    dfs(0, v);
    cout << ans << endl;
    return 0;
}