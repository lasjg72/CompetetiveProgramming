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

void dfs(string s, char now){
    if(s.size() == n){
        cout << s << " ";
        return ;
    }
    for(char c = 'a'; c <= now+1; c++){
        string t = s;
        t += c;
        dfs(t, max(now, c));
    }
}

int main()
{
    cin >> n;
    dfs("", 'a'-1);
    cout << endl;
    return 0;
}