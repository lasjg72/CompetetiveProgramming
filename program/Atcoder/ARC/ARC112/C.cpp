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

/**
int dfs(vector<vector<int>> g, vector<int> size, vector<int> f, int x){
    int sum = 0;
    vector<int> seq;
    for(int to : g[x]){
        dfs(g, size, f, to);
        size[x] += size[to];
        if(size[to] % 2){
            seq.push_back(f[to]);
        }else{
            if(f[to] >= 0){
                f[x] += f[to];
            }else{
                f[x] -= f[to];
            }
        }
    }
    sort(seq.begin(), seq.end(), greater<int>());
    //seq.push_back(sum);
    for(int i = 0; i < seq.size(); i++){
        if(i % 2){
            f[x] -= seq[i];
        }else{
            f[x] += seq[i];
        }
    }
    cout << "x: " << x << " f[x]: " << f[x] << endl;
    return f[x];
}
**/

int main()
{
    int n;
    cin >> n;
    vector<int> p(n, -1);
    for(int i = 1; i < n; i++){
        cin >> p[i];
        p[i]--;
    }
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++){
        g[p[i]].push_back(i);
    }
    vector<int> f(n, 1);
    vector<int> size(n, 1);
    const auto rec = [&](auto &&rec, int x) -> void {
        int sum = 0;
        vector<int> seq;
        for(int to : g[x]){
            rec(rec, to);
            size[x] += size[to];
            if(size[to] % 2){
                seq.push_back(f[to]);
            }else{
                if(f[to] >= 0){
                    f[x] += f[to];
                }else{
                    sum += f[to];
                }
            }
        }
        sort(seq.begin(), seq.end(), greater<int>());
        seq.push_back(sum);
        for(int i = 0; i < seq.size(); i++){
            if(i % 2){
                f[x] -= seq[i];
            }else{
                f[x] += seq[i];
            }
        }
    };
    rec(rec, 0);
    // for(int i = 0; i < n; i++){
    //     cout << f[i] << endl;
    // }    
    cout << (n+f[0])/2 << endl;   
    //cout << dfs(g, size, f, 0) << endl;
    return 0;
}