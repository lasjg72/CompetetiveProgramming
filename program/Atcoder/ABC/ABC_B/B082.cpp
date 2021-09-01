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
    sort(s.begin(), s.end());
    map<char, int> mp;
    for(int i = 0; i < t.size(); i++){
        mp[t[i]]++;
    }
    for(int i = 0; i < s.size(); i++){
        for(char c = s[i]+1; c <= 'z'; c++){
            if(mp[c] > 0){
                cout << "Yes" << endl;
                return 0;
            }
        }
        if(mp[s[i]] > 0) mp[s[i]]--;
        else{
            cout << "No" << endl;
            return 0;
        }
    }
    if(s.size() == t.size()){
        cout << "No" << endl;
    }else cout << "Yes" << endl;
    return 0;
}