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
    string ans = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1'){
            ans += '1';
        }else if(s[i] == '0'){
            ans += '0';
        }else if(ans.size() != 0 && s[i] == 'B'){
            ans.pop_back();
        }
    }
    cout << ans << endl;
    return 0;
}