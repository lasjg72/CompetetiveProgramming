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
set<int> res;

void prime(int n){
    for(int i = 2; i*i <= n; i++){
        if(n%i != 0) continue;
        while(n%i == 0){
            n /= i;
        }
        res.insert(i);
    }
    if(n != 1) res.insert(n);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<bool> ok(m+1, true);
    //set<int> res;
    for(int i = 0; i < n; i++){
        prime(a[i]);
    }
    for(int now : res){
        for(int i = now; i <= m; i += now) ok[i] = false;
    }
    int ans = 0;
    for(int i = 1; i <= m; i++) if(ok[i]) ans++;
    cout << ans << endl;
    for(int i = 1; i <= m; i++) if(ok[i]) cout << i << endl;
    return 0;
}