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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(n));
    vector<vector<char>> b(m, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
        }
    }
    for(int i = 0; i < n-m+1; i++){
        for(int j = 0; j < n-m+1; j++){
            bool suc = false;
            for(int k = 0; k < m; k++){
                if(suc) break;
                for(int l = 0; l < m; l++){
                    if(k == m-1 && l == m-1 && a[i+k][j+l] == b[k][l]){
                        cout << "Yes" << endl;
                        return 0;
                    }
                    if(a[i+k][j+l] == b[k][l]) continue;
                    else{
                        suc = true;
                        break;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}