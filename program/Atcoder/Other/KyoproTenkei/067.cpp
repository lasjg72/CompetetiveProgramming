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

ll to10(string s){
    int n = s.size();
    ll tmp = 1, ans = 0;
    for(int i = n-1; i >= 0; i--){
        ans += (s[i]-'0')*tmp;
        tmp *= 8;
    }
    return ans;
}

string to9(ll n){
    string res;
    if(n == 0) return to_string(n);
    while(n>0){
        string tmp;
        if(n%9 == 8){
            tmp = "5";
        }else{
            tmp = to_string(n%9);
        }
        res.insert(0, tmp);
        n /= 9;
    }
    return res;
}

int main()
{
    string n;
    int k;
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        n = to9(to10(n));
    }
    cout << n << endl;
    return 0;
}