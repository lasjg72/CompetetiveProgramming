#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    string ans;
    while(n){
        n--;
        ans += string(1,'a'+n%26);
        n /= 26;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}