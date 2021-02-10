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

int main()
{
    int n, d;
    cin >> n >> d;
    vector<vector<int>> x(n, vector<int>(d));
    for(int i = 0; i<n; i++){
        for(int j =0; j<d; j++){
            cin >> x[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i< n; i++){
        for(int j = 0; j<i; j++){
            int naka = 0;
            for(int k = 0; k < d; k++){
                int s = x[i][k]-x[j][k];
                naka += s * s;
            }
            int s = sqrt(naka)+0.1;
            if(s * s == naka) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}