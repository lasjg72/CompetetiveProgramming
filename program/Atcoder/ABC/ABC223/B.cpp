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
    cin >> s;
    vector<string> ans;
    for(int i = 0; i < s.size(); i++){
        string tmp = "";
        for(int j = 0; j < s.size(); j++){
            tmp += s[(i+j)%(s.size())];
        }
        ans.push_back(tmp);
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] << endl;
    cout << ans[s.size()-1] << endl;
    return 0;
}