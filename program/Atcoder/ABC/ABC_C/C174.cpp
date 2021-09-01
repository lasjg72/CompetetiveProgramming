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
    int k;
    cin >> k;
    vector<bool> used(k, false);
    int now = 7%k;
    int ans = 1;
    while(!used[now]){
        if(now == 0){
            cout << ans << endl;
            return 0;
        }
        used[now] = true;
        now = (now*10+7)%k;
        ans++;
    }
    cout << -1 << endl;
    return 0;
}
