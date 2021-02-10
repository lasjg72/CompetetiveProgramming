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
    string s, t;
    cin >> n >> s >> t;
    string ans = "";
    for(int i = 0; i< n; i++){
        ans = ans + s[i] + t[i];
    }
    cout << ans << endl;
    return 0;
}