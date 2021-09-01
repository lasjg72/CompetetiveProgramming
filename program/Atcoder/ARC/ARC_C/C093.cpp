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
    vector<int> a(n), sum(n+2, 0);
    int pos = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum[i+1] = sum[i]+abs(a[i]-pos);
        pos = a[i];
    }
    sum[n+1] = sum[n]+abs(a[n-1]);
    for(int i = 0; i < n; i++){
        int ans = sum[i];
        ans += sum[n+1]-sum[i+2];
        if(i != 0 && i+1 < n){
            ans += abs(a[i-1]-a[i+1]);
        }else if(i == 0){
            ans += abs(a[1]);
        }else{
            ans += abs(a[i-1]);
        }
        cout << ans << endl;
    }
    return 0;
}