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
    vector<int> a(n, 0), p(n, 0), x(n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> p[i] >> x[i];
    }
    int ans = 1001001001;
    for(int i = 0; i < n; i++){
        if(x[i]-a[i] > 0){
            ans = min(ans, p[i]);
        }
    }
    if(ans == 1001001001) ans = -1;
    cout << ans << endl;
    return 0;
}