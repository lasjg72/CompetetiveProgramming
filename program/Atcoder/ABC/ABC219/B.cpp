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
    vector<string> s(3);
    cin >> s[0] >> s[1] >> s[2];
    string t;
    cin >> t;
    string ans = "";
    for(int i = 0; i < t.size(); i++){
        int a = t[i]-'0';
        a--;
        ans += s[a];
    }
    cout << ans << endl;
    return 0;
}