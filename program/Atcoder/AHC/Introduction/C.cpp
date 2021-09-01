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

int D;
int s[366][27];
int t[366], c[27], last[27];

ll score(int d, int q){
    t[d] = q;
    int ans = 0;
    for(int i = 1; i <= D; i++){
        ans += s[i][t[i]];
        int res = 0;
        last[t[i]] = i;
        for(int j = 1; j <= 26; j++){
            res += c[j]*(i-last[j]);
        }
        ans -= res;
    }
    return ans;
}

int main()
{
    cin >> D;
    for(int i = 1; i <= 26; i++) cin >> c[i];
    for(int i = 1; i <= D; i++){
        for(int j = 1; j <= 26; j++) cin >> s[i][j];
    }
    for(int i = 1; i <= D; i++){
        cin >> t[i];
    }

    int ans = 0;
    for(int i = 1; i <= D; i++){
        ans += s[i][t[i]];
        int res = 0;
        last[t[i]] = i;
        for(int j = 1; j <= 26; j++){
            res += c[j]*(i-last[j]);
        }
        ans -= res;
    }

    int M;
    cin >> M;
    while(M--){
        int d, q;
        cin >> d >> q;
        for(int i = 1; i <= 26; i++) last[i] = 0;
        ans = score(d, q);
        cout << ans << endl;
    }
    return 0;
}