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
    int n, m, Q;
    cin >> n >> m >> Q;
    vector<int> l(m), r(m);
    vector<vector<int>> sum(n+1, vector<int>(n+1, 0));
    for(int i = 0; i < m; i++){
        cin >> l[i] >> r[i];
        sum[l[i]][r[i]]++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            sum[i][j] += sum[i-1][j];
            sum[i][j] += sum[i][j-1];
            sum[i][j] -= sum[i-1][j-1];
        }
    }
    for(int i = 0; i < Q; i++){
        int p, q;
        cin >> p >> q;
        int ans = sum[q][q]-sum[p-1][q]-sum[q][p-1]+sum[p-1][p-1];
        cout << ans << endl;
    }

    return 0;
}