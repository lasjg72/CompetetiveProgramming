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
    int sn = s.size();
    
    int ans = 0;
    int l = 0, r = sn-1;
    while(l != r){
        if(s[l] == s[r]){
            l++;
            r--;
            if(r < l) break;
        }else if(s[l] == 'x'){
            ans++;
            l++;
        }else if(s[r] == 'x'){
            ans++;
            r--;
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}