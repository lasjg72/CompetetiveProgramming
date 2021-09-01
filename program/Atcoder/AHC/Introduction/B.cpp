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
    int D;
    cin >> D;
    vector<int> c(27);
    for(int i = 1; i <= 26; i++) cin >> c[i];
    vector<vector<int>> s(D+1, vector<int>(27));
    for(int i = 1; i <= D; i++){
        for(int j = 1; j <= 26; j++) cin >> s[i][j];
    }
    vector<int> t(D+1);
    for(int i = 1; i <= D; i++){
        cin >> t[i];
    }
    vector<int> last(27, 0);

    int ans = 0;
    for(int i = 1; i <= D; i++){
        ans += s[i][t[i]];
        int res = 0;
        last[t[i]] = i;
        for(int j = 1; j <= 26; j++){
            res += c[j]*(i-last[j]);
        }
        ans -= res;
        cout << ans << endl;
    }
    return 0;
}