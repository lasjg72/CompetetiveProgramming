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
    vector<vector<string>> ans(n+1);
    ans[1].push_back("a");
    for(int i = 2; i <= n; i++){
        for(string s: ans[i-1]){
            int mx = 0;
            for(int j = 0; j < s.size(); j++){
                mx = max(mx, (int)s[j]);
            }
            for(int j = 0; j < mx-(int)'a'+2; j++){
                string now = s + ((char)('a'+j));
                ans[i].push_back(now);
            }
        }
    }
    for(string s: ans[n]){
        cout << s << " ";
    }
    cout << endl;
    return 0;
}