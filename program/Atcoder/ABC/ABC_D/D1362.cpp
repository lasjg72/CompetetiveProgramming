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
    ll k;
    cin >> n >> k;
    vector<int> a(n), s(n+1, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s[i+1] = s[i]+ a[i];
    }
    ll sum = 0, ans = 0;;
    int r = 0;
    //int num = n - (lower_bound(s.begin(), s.end(), k) - s.begin() - 1) + 1;
    for(int i = 0; i < n; i++){
        while(sum < k){
            if(r == n) break;
            else{
                sum += a[r];
                r++;
            }
        }
        if(sum < k) break;
        ans += n-r+1;
        sum -= a[i];
    }

    cout << ans << endl;
    return 0;
}