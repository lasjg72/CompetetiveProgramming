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
    int a, b;
    cin >> a >> b;
    ll k;
    cin >> k;
    vector<vector<ll>> com(61, vector<ll>(61, 0));
    com[0][0] = 1;
    for(int i = 1; i <= 60; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i) com[i][j] = 1;
            else com[i][j] = com[i-1][j-1]+com[i-1][j];
            //cout << com[i][j] << " ";
        }
        //cout << endl;
    }
    string ans = "";
    while(a+b>0){
        //cout << "a: " << a << " b: " << b << " k: " << k << endl;
        if(com[a+b-1][b] >= k){
            ans += 'a';
            a--;
        }else{
            ans += 'b';
            //cout << com[a+b-1][b] << endl;
            k -= com[a+b-1][b];
            b--;
        }
    }
    cout << ans << endl;
    return 0;
}