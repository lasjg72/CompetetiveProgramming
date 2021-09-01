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

int t[5][5];
int n, k;
bool dfs(int num, int val = 0){
    //cout << "num: " << num << " val: " << val << endl;
    //cout << n << endl;
    if(num == n) return (val == 0);
    for(int i = 0; i < k; i++){
        //cout << "t[num][i]: " << t[num][i] << endl;
        if(dfs(num+1, val^t[num][i])) return true;
    }
    return false;
}

int main()
{
    cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cin >> t[i][j];
        }
    }
    if(dfs(0)) cout << "Found" << endl;
    else cout << "Nothing" << endl;
    return 0;
}
