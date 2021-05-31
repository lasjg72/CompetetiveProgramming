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
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<set<int>> v(26);
    for(int i = 0; i < n; i++){
        v[s[i]-'a'].insert(i);
    }
    while(q--){
        int m;
        cin >> m;
        if(m == 1){
            int p;
            cin >> p;
            char c;
            cin >> c;
            p--;
            v[s[p]-'a'].erase(p);
            s[p] = c;
            v[s[p]-'a'].insert(p);
        }else{
            int l, r;
            cin >> l >> r;
            l--; r--;
            int ans = 0;
            for(int i = 0; i < 26; i++){
                auto itr = v[i].lower_bound(l);
                if(itr != v[i].end() && *itr <= r) ans++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}