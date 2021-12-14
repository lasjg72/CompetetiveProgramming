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
    string x;
    cin >> x;
    int n;
    cin >> n;
    map<char, char> mp;
    map<char, char> mp2;
    for(int i = 0; i < 26; i++){
        mp[x[i]] = 'a'+i;
        mp2['a'+i] = x[i];
    }
    vector<string> ans;
    for(int i = 0; i < n; i++){
        string s;
        string t = "";
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            t += mp[s[j]];
        }
        ans.push_back(t);
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < n; i++){
        string s = ans[i];
        string t = "";
        for(int j = 0; j < s.size(); j++){
            t += mp2[s[j]];
        }
        cout << t << endl;
    }
    return 0;
}