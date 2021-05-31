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
    int l = 0, r = 0;
    ll ans = 0;
    while(l < n){
        while(r+1 != n && a[r] < a[r+1]) r += 1;
        // cout << "----" << endl;
        // cout << l << endl;
        // cout << r << endl;
        ans+= r-l+1;
        l++;
        if(l > r) r = l;
    }
    cout << ans << endl;
    return 0;
}