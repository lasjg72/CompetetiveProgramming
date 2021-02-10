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

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    string n;
    cin >> n;

    int ans = 0;
    bool ok = false;
    for(int i = 1; i < n.size(); i++){
        if(n[i]-'0' != 9) ok =true;
    }
    if(n.size() == 1){
        ans = n[0]-'0';
    }else if(ok){
        ans = (n.size()-1) * 9 + (n[0] - '0')-1;
    }else{
        ans = (n.size()-1) * 9 + (n[0] - '0');
    }
    cout << ans << endl;
    return 0;
}