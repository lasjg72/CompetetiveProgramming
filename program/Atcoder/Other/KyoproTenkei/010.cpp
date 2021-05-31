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
    vector<int> c(n);
    vector<ll> p(n), s1(n+1, 0), s2(n+1, 0);
    for(int i = 0; i < n; i++){
        cin >> c[i] >> p[i];
        if(c[i] == 1){
            s1[i+1] = s1[i] + p[i];
            s2[i+1] = s2[i];
        }else{
            s1[i+1] = s1[i];
            s2[i+1] = s2[i] + p[i];
        }
        //cout << s1[i+1] << " " << s2[i+1] << endl;
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << s1[r+1]-s1[l] << " " << s2[r+1]-s2[l] << endl;
    }
    return 0;
}