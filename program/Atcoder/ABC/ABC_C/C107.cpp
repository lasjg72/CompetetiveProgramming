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
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    int ans = 1001001001;;
    for(int i = 0; i < n-k+1; i++){
        ans = min(ans, min(abs(x[i])+abs(x[i]-x[i+k-1]), abs(x[i+k-1])+abs(x[i+k-1]-x[i])));
    }
    cout << ans << endl;
    return 0;
}