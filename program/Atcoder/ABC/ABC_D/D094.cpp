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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int mx = a.back();
    int sa = 1001001001;
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        sa = min(sa, abs(mx/2-a[i]));
        if(sa == abs(mx/2-a[i])){
            ans = a[i];
        }
    }
    cout << mx << " " << ans << endl;
    return 0;
}