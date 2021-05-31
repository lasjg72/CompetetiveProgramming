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
    vector<int> a(n), sum(n+1, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum[i+1] = sum[i] + a[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            if(j > )
        }
    }
    return 0;
}