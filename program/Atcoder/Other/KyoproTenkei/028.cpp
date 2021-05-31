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
    int n;
    cin >> n;
    vector<int> lx(n), ly(n), rx(n), ry(n);
    vector<vector<int>> g(1009, vector<int>(1009, 0));
    for(int i = 0; i < n; i++){
        cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];
        g[lx[i]][ly[i]]++;
        g[lx[i]][ry[i]]--;
        g[rx[i]][ly[i]]--;
        g[rx[i]][ry[i]]++;
    }

    // for(int i = 5; i >= 0; i--){
    //     for(int j = 0; j <= 5; j++){
    //         cout << g[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    
    for(int i = 0; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++){
            g[i][j] += g[i][j-1]; 
            //cout << "x: " << j << " y: " << i << " g: " << g[j][i] << endl; 
        }
    }
    for(int i = 1; i <= 1000; i++){
        for(int j = 0; j <= 1000; j++){
            g[i][j] += g[i-1][j];
        }
    }
    //cout << "---" << endl;
    vector<int> ans(1000005, 0);
    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= 1000; j++){
            if(g[i][j] >= 1) ans[g[i][j]]++;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}