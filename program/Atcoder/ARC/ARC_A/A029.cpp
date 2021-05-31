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
    vector<int> t(n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
    int ans = 1001001001;
    for(int bit = 0; bit < (1<<n); bit++){
        int tmp1 = 0, tmp2 = 0;
        for(int i = 0; i < n; i++){
            if(bit & (1<<i)){
                tmp1 += t[i];
            }else{
                tmp2 += t[i];
            }
        }
        ans = min(ans, max(tmp1, tmp2));
    }
    cout << ans << endl;
    return 0;
}