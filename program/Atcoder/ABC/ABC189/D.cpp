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
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    ll ans = 0;
    for(int i = n-1; i >= 0; i--){
        if(i == 0){
            if(s[i] == "OR"){
                ans += 3;
            }else{
                ans += 1;
            }
        }else{
            if(s[i] == "OR"){
                ans += (ll)pow(2, i+1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}