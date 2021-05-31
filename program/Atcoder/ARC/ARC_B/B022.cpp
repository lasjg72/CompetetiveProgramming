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
    map<int, int> mp;
    for(int i = 0; i < n; i++) cin >> a[i];
    int r = 0, ans = 0;
    for(int i = 0; i < n; i++){
        while(r < n){
            if(mp[a[r]] == 0) mp[a[r++]]++;
            else break;
        }
        ans = max(ans, r-i);
        mp[a[i]]--;
    }
    cout << ans << endl;
    return 0;
}