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
    string s;
    cin >> s;
    ll ans = 0;
    vector<ll> a(s.length()+1, 0);

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '<'){
            if(a[i] >= a[i+1]) a[i+1] = max(a[i+1], a[i]+1);
        }
    }
    for(int i = s.length()-1; i >=0; i--){
        if(s[i] == '>' && a[i] <= a[i+1]){
            a[i] = max(a[i], a[i+1]+1);
        }
    }
    for(int i = 0; i < s.length()+1; i++){
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}