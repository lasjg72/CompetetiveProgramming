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
    int num = 4-s.size();
    string ans;
    for(int i = 0; i < num; i++){
        ans += '0';
    }
    ans += s;
    cout << ans << endl;
    return 0;
}
