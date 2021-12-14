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
    cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    int ans = n;
    for(int i = 0; i < n; i++){
        bool ok = false;
        for(int a = 1; a <= 250; a++){
            for(int b = 1; b <= 250; b++){
                if(4*a*b+3*a+3*b == s[i]) ok = true;
            }
        }
        if(ok) ans--;
    }
    cout << ans << endl;
    return 0;
}