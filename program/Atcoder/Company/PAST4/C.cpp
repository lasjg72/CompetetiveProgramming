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
    vector<vector<char>> s(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j< m; j++){
            cin >> s[i][j];
        }
    }

    int x[] = {0, 1, 1, 0, -1, -1, -1, 0, 1};
    int y[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int num = 0;
            for(int k = 0; k < 9; k++){
                if(i + x[k] >= n || i + x[k] < 0 || j + y[k] >= m || j + y[k] < 0) continue;
                if(s[i + x[k]][j + y[k]] == '#') num++;
            }
            cout << num;
        }
        cout << endl;
    }
    return 0;
}