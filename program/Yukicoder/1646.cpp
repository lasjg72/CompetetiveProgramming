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
const int mod = 998244353;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 1;
    if(n == 1){
        if(s[0] == '?'){
            cout << 26 << endl;
        }else cout << 1 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(i != n-1 && s[i] != '?' && s[i] == s[i+1]) ans = 0;
        if(i == n-1 && s[i] == '?') ans = (ans*25)%mod;
        if(s[i] == '?'){
            if(i == 0){
                if(s[i+1] == '?'){
                    ans *= 26;   
                }else{
                    ans *= 25;
                }
            }else{
                if(s[i-1] == '?' && s[i+1] == '?') ans = (ans*25)%mod;
                else if(s[i-1] == '?' && s[i+1] != '?') ans = (ans*24)%mod;
                else if(s[i-1] != '?' && s[i+1] == '?') ans = (ans*25)%mod;
                else if(s[i-1] != '?' && s[i+1] != '?'){
                    if(s[i-1] == s[i+1]) ans = (ans*25)%mod;
                    else ans = (ans*24)%mod;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}