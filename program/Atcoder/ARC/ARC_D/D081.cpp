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
const int mod = 1000000007;

char s[2][53];
int num[2][53];
int n;
ll ans;

void dfs(int i, int j){
    if(s[i][j] == s[i+1][j]){
        if(j == 0) {
            ans *= 3;
            if(j+1 < n)
            dfs(i, j+1);
        }
        else if(s[i][j-1] != s[i+1][j-1]){
            if(j+1 < n)
            dfs(i, j+1);
        }else{
            ans = (ans*2) % mod;
            if(j+1 < n)
            dfs(i, j+1);
        }
    }else{ // パネル2枚
        if(j == 0) {
            ans *= 6;
            if(j+2 < n)
            dfs(i, j+2);
        }
        else if(s[i][j-1] != s[i+1][j-1]){
            ans = (ans*3) % mod;
            if(j+2 < n)
            dfs(i, j+2);
        }else{
            ans = (ans*2) % mod;
            if(j+2 < n)
            dfs(i, j+2);
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            cin >> s[i][j];
        }
    }
    ans = 1;
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}