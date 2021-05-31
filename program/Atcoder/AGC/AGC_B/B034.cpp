#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <stack> 
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
    
    ll num = 0, ans = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A') num++;
        else if(i+1 < s.size() && s[i] == 'B' && s[i+1] == 'C') {
            ans += num;
            i++;
        }
        else num = 0;

        // cout << "i: " << i << endl;
        // cout << "num: " << num << endl;
    }
    cout << ans << endl;
    return 0;
}