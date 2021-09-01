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
    string s;
    cin >> n >> s;
    ll ans = (ll)(n+1)*n/2;
    char c = s[0];
    ll num = 1;
    for(int i = 1; i < n; i++){
        if(s[i] != c){
            ans -= (num+1)*num/2;
            num = 1;
            c = s[i];
        }else{
            num++;
        }
    }
    ans -= (num+1)*num/2;
    cout << ans << endl;
    return 0;
}