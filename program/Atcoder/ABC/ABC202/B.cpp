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
    string ans = "";
    for(int i = n-1; i >= 0; i--){
        if(s[i] == '0'){
            ans += "0";
        }else if(s[i] == '1'){
            ans += "1";
        }else if(s[i] == '6'){
            ans += "9";
        }else if(s[i] == '8'){
            ans += "8";
        }else if(s[i] == '9'){
            ans += "6";
        }
    }
    cout << ans << endl;
    return 0;
}