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
    string s;
    cin >> s;
    int l = 0, r = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '.') l++;
        if(s[i] == '#') break;
    }
    for(int j = s.size()-1; j >= 0; j--){
        if(s[j] == '.') r++;
        if(s[j] == '#') break;
    }
    int mx = 0, tmp = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '.') tmp++;
        if(s[i] == '#'){
            mx = max(mx, tmp);
            tmp = 0;
        }
        if(i == s.size()-1){
            mx = max(mx, tmp);
        }
    }
    if(l < r){
        int ans = max(mx-l, r);
        cout << l << " " << ans << endl;
    }else{
        int ans = max(mx-r, l);
        cout << ans << " " << r << endl;
    }
    return 0;
}