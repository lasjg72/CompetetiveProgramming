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
    string ans = "";
    for(int i = 0; i < 26; i++){
        int p;
        cin >> p;
        char a = 'a'+ (p-1);
        ans += a;
    }
    cout << ans << endl;
    return 0;
}