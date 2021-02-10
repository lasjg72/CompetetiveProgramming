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
    int mid = 0;
    if(s.size() % 2 == 0){
        mid = s.size()/2 -1;
    }else{
        mid = (s.size()-1)/2;
    }
    int ans = 0;
    for(int i = 0; i <= mid ; i++){
        if(s[i] == s[s.size()-1-i]) continue;
        else ans++;
    }
    cout << ans << endl;
    return 0;
}