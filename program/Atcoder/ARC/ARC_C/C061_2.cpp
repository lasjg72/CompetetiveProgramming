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
int num;
ll ans;

ll calc(string s){
    ll res = 0;
    int pos = 0;
    //cout << s << endl;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == '+'){
            res += stoll(s.substr(pos, i-pos));
            pos = i+1;
        }
    }
    res += stoll(s.substr(pos, s.size()-pos));
    return res;
}

void dfs(string s, int pos=0){
    if(pos == s.size()-1){
        ans += calc(s);
        return ;
    }
    // +を入れる場合
    // cout << "s: " << s << endl;
    // cout << "pos: " << pos << endl;
    string t = s;
    dfs(t.insert(pos+1, "+"), pos+2);
    // +を入れない場合
    dfs(s, pos+1);
}

int main()
{
    string s;
    cin >> s;
    num = s.size();
    dfs(s);
    cout << ans << endl;
    return 0;
}