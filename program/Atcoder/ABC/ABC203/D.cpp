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
    vector<vector<ll>> a(n, vector<ll>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    vector<vector<int>> num(n, vector<int>(n, 0));
    int l = 0, r = 1001001001;
    while(r-l>1){
        int mid = (l+r)/2;
        
    }
    cout << r << endl;
    return 0;
}