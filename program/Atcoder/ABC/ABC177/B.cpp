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
    string s, t;
    cin >> s >> t;
    int ans = 1001001001;
    for(int i = 0; i < s.length()-t.length()+1; i++){
        int len = 0;
        for(int j = 0; j < t.length(); j++){
            if(s[i+j] != t[j]){
                len++;
            }
        }
        ans = min(ans, len);
    }
    cout << ans << endl;
    return 0;
}