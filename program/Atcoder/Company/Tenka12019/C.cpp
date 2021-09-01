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
    string s;
    cin >> s;
    vector<int> w(n+1, 0), b(n+1, 0);
    int ans = 1001001001;
    for(int i = 0; i < n; i++){
        if(s[i] == '#'){
            b[i+1] = b[i]+1;
            w[i+1] = w[i];
        }else{
            b[i+1] = b[i];
            w[i+1] = w[i]+1;
        }
    }
    for(int i = 0; i < n-1; i++){
        if(s[i] == '.' && s[i+1] == '#'){
            ans = min(ans, b[i+1]+w[n]-w[i+1]);
        }
    }
    if(ans == 1001001001) ans = min(b[n], w[n]);
    cout << ans << endl;
    return 0;
}
