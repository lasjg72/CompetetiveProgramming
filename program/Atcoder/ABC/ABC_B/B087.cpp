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

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    int ans = 0;
    for(int i = 0; i< a+1; i++){
        int tmp = 0;
        tmp += 500 * i;
        for(int j = 0; j < b +1; j++){
            int tmp1 = tmp;
            tmp1 += 100 * j;
            for(int k = 0; k < c + 1; k++){
                int tmp2 = tmp1;
                tmp2 += 50 * k;
                if(tmp2 == x) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}