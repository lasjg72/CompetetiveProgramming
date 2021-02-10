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
    char now;
    bool ok = false;
    map<string, int> a;
    for(int i = 0; i< n; i++){
        string s;
        cin >> s;
        if(a[s] == 1) ok = true;
        a[s]++;
        if(i != 0){
            if(now == s[0]){ 
                now = s[s.length()-1];
                continue;
            }
            else{
                ok = true;
            }
        }
        now = s[s.length()-1];
    }
    if(ok){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}