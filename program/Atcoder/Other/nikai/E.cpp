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
    int k;
    string s;
    cin >> k >> s;
    vector<string> a;
    a.push_back(s);
    while(k--){
        if(a[0].size() == 0 || a[0].size() == 1){
            cout << "impossible" << endl;
            return 0;
        }
        vector<string> ts;
        for(int i = 0; i < a.size(); i++){
            string ns = a[i];
            string tmp = "";
            int now = ns.size()/2;
            for(int j = 0; j < now-1; j++){
                tmp += ns[j];
            }
            ts.push_back(tmp);
            tmp = "";
            for(int j = ns.size()-now; j < ns.size(); j++){
                tmp += ns[j];
            }
            ts.push_back(tmp);
        }
        a = ts;
        
    }
    int num = a[0].size();
    ll ans = 0;
    for(int i = 0; i < num; i++){
        map<char, int> mp;
        for(string ns : a){
            mp[ns[i]]++;
        }
        int tmp = 0;
        for(char c = 'a'; c <= 'z'; c++){
            tmp = max(tmp, mp[c]);
        }
        ans += a.size()-tmp;
    }
    cout << ans << endl;
    return 0;
}