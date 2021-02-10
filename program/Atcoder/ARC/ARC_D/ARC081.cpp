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
const ll mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    ll ans = 1;
    if(n == 1){
        cout << 3 << endl;
        return 0;
    }else if(n == 2){
        cout << 12 << endl;
        return 0;   
    }
    else if(n%3 == 0){
        for(int i = 0; i < n/3; i++){
            ans = ans * 6 % mod;
        }
    }else if(n%3 == 1){
        for(int i = 0; i < n/3; i++){
            ans = ans * 6 % mod;
        }
        ans = ans * 2 % mod;
    }else if(n%3 == 2){
        for(int i = 0; i < n/3; i++){
            ans = ans * 6 % mod;
        }
        ans = ans * 2 % mod;
        ans = ans * 2 % mod;
    }
    cout << ans << endl;
    return 0;
}