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
    int n, k;
    cin >> n >> k;
    int mx = (n-1)*(n-2)/2;
    if(k > mx){
        cout << -1 << endl;
        return 0;
    }
    if(k == mx){
        int m = n-1;
        cout << m << endl;
        for(int i = 0; i < m; i++){
            cout << 1 << " " << i+2 << endl;
        }
    }else{
        vector<vector<int>> g(n, vector<int>(n, 0));
        int m = n*(n-1)/2-k;
        cout << m << endl;
        for(int i = 0; i < n-1; i++){
            cout << 1 << " " << i+2 << endl;
            g[0][i+1] = 1;
            m--;
            if(m == 0) return 0;
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(g[i][j] == 0){
                    m--;
                    g[i][j] = 1;
                    cout << i+1 << " " << j+1 << endl;
                    if(m == 0) return 0;
                }
            }
        }
    }
    return 0;
}