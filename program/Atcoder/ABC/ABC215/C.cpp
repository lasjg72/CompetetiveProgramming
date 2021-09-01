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
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    vector<int> per(n, 0);
    for(int i = 0; i < n; i++) per[i] = i;
    set<string> ans;
    do{
        string now = "";
        for(int i = 0; i < n; i++) now += s[per[i]];
        ans.insert(now);
    }while(next_permutation(per.begin(), per.end()));
    
    //sort(ans.begin(), ans.end());
    //for(string res : ans) cout << res << endl;
    auto itr = ans.begin();
    for(int i = 0; i < k-1; i++) itr++;
    cout << *itr << endl;
    //cout << ans[k-1] << endl;
    return 0;
}