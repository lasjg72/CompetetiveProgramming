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
    bool ok = true;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != t[i]) cnt++;
    }
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] != t[i] && s[i+1] != t[i+1]){
            if(s[i] == t[i+1] && s[i+1] == t[i]){
                if(ok) ok = false;
                else{
                    cout << "No" << endl;
                    return 0;
                }
                i++;
            }else{
                cout << "No" << endl;
                return 0;
            }
        }
    }
    if(cnt == 0 || cnt == 2){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}