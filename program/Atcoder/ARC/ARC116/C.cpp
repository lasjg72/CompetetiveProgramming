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
ll ans = 0;
vector<ll> res[200005];

void dfs(ll d, ll num){
    
    ll size = res[d].size();
    //ans *= size;
    if(num == 1){
        ans++;
        return ;
    }
    num--;
    for(int i = 0; i < size; i++){
        dfs(res[d][i], num);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j*j <= i; j++){
            if(i%j == 0){
                res[i].push_back(j);
                if(i/j != j) res[i].push_back(i/j);
            }
        }
    }
    for(int i = 1; i <= m; i++){
        //cout << "i: " << i << endl;
        dfs(i, n);
        //cout << "ans: " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}