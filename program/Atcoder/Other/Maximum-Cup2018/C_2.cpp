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

vector<vector<int>> g;
int n, bnum, wnum;
vector<int> used;

void dfs(int x, int num){
    for(int to : g[x]){
        //cout << "to: " << to << endl;
        if(used[to] == num){
            //cout << "to: " << to << " num: " << num << endl;
            cout << -1 << endl;
            exit(0);
        }
        if(used[to] >= 0) continue;
        used[to] = num+1;
        //cout << "used: " << used[to] << endl;
        if(num == 0) bnum++;
        else wnum++;
        dfs(to, (num+1)%2);
    }
}

int main()
{
    cin >> n;
    g.resize(n);
    used.resize(n, -1);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        a--;
        g[i].push_back(a);
        g[a].push_back(i);
    }
    for(int i = 0; i < n; i++){
        if(used[i] < 0) {
            used[i] = 0;
            dfs(i, 0);
        }
    }
    cout << max(bnum, wnum) << endl;   
    return 0;
}