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
    vector<int> a(n), ans(n);
    ll tot = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        tot += a[i];
    }
    ans[0] = tot;
    for(int i = 1; i < n; i += 2) {
        ans[0] -= (2 * a[i]);
    }

    for(int i = 0; i < n; i++){
        if(i+1 == n){
            ans[0] = 2 * a[i] - ans[i];
        }else{
            ans[i+1] = 2 * a[i] - ans[i];
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}