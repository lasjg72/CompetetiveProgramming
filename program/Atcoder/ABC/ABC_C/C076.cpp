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

void ng(){
    cout << "UNRESTORABLE" << endl;
    exit(0);
}

int main()
{
    string s, t;
    cin >> s >> t;
    
    if(s.size() < t.size()) ng();

    string ans = "";
    for(int i = s.size()-1; i >= t.size()-1; i--){
        string tmp = s;
        bool flag = true;
        for(int j = t.size()-1; j >= 0; j--){
            if(tmp[i-(t.size()-1-j)] != '?' && tmp[i-(t.size()-1-j)] != t[j]) flag = false;
        }
        if(flag){
            for(int j = t.size()-1; j >= 0; j--){
                if(tmp[i-(t.size()-1-j)] == '?') {
                    tmp[i-(t.size()-1-j)] = t[j];
                }
            }
            for(int j = 0; j < tmp.size(); j++){
                if(tmp[j] == '?') tmp[j] = 'a';
            }
            ans = tmp;
            break;
        }
    }
    if(ans == "") ng();
    else cout << ans << endl;
    return 0;
}