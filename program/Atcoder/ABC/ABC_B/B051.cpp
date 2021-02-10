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
    int k, s;
    cin >> k >> s;
    int ans = 0;
    for(int i = 0; i <= k; i++){
        for(int j = 0; j <= k; j++){
            if(s - (i + j) <= k && s - (i + j) >= 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}