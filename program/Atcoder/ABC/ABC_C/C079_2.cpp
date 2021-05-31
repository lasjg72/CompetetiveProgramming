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
string ans;

void dfs(string s, int pos = 0){
    if(s.size()-1 == pos){
        //cout << "s: " << s << endl;
        int num = 1, tmp = stoi(s.substr(0, 1));
        for(int i = 0; i < 3; i++){
            if(s[num] == '+'){
                tmp += stoi(s.substr(num+1, 1));
            }else{
                tmp -= stoi(s.substr(num+1, 1));
            }
            num += 2;
        }
        if(tmp == 7) ans = s;
        return ;
    }
    string t = s;
    dfs(t.insert(pos+1, "+"), pos+2);
    dfs(s.insert(pos+1, "-"), pos+2);
    return;
}

int main()
{
    string s;
    cin >> s;
    dfs(s);
    cout << ans+"=7" << endl;
    return 0;
}