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
    string s;
    cin >> s;
    int n = s.size();
    int ans = 1001001001;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    bool ok = true;
    for(int i = 0; i < n-1; i++){
        if(s[i] != s[i+1]){
            ok = false;
            ans = min(ans, max(i+1, n-i-1));
        }
    }
    if(ok){
        cout << n << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}