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

int n;
vector<string> ans;

void dfs(string s, int num){
    int m = s.size();
    if(m == n){
        ans.push_back(s);
        return;
    }

    for(char c = 'a'; c <= 'a'+num; c++){
        if(c == 'a'+num) dfs(s+c, num+1);
        else dfs(s+c, num);
    }
}

int main()
{
    cin >> n;
    dfs("a", 1);
    sort(ans.begin(), ans.end());
    for(string s : ans){
        cout << s << endl;
    }
    return 0;
}