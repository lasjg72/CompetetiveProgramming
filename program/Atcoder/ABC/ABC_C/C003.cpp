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
    vector<int> r(n);
    for(int i = 0; i < n; i++){
        cin >> r[i];
    }
    sort(r.rbegin(), r.rend());
    double ans = 0;
    for(int i = 0; i < k; i++){
        ans = (ans + (double)r[k-1-i])/2; 
        // cout << "r: " << r[k-1-i] << endl;
        // cout << ans << endl;      
    }
    printf("%.7f\n", ans);
    return 0;
}