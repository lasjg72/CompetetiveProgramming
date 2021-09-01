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
    string s;
    cin >> s;
    vector<int> a(n, 0), b(n, 0);
    for(int i = 0; i < n-1; i++){
        if(s[i] == 'E'){
            a[i+1] = a[i]+1;
        }else{
            a[i+1] = a[i];
        }
    }
    for(int i = n-1; i >= 1; i--){
        if(s[i] == 'W'){
            b[i-1] = b[i]+1;
        }else{
            b[i-1] = b[i];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int now = a[i]+b[i];
        //cout << "now: " << now << endl;
        ans = max(ans, now);
    }
    cout << n-ans-1 << endl;
    return 0;
}