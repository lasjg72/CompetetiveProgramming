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
    // ll k;
    // cin >> k;
    // if(k % 2 == 0 || k % 5 == 0){
    //     cout << -1 << endl;
    //     return 0;
    // }
    // ll keta = k % 10;
    // ll bai;
    // if(keta == 1) bai = 7;
    // if(keta == 3) bai = 9;
    // if(keta == 7) bai = 1;
    // if(keta == 9) bai = 3;

    // ll tmp = 0;
    // while(tmp <= k){
    //     ll num = k * bai;
    //     cout << "num: " << num << endl;
    //     string s;
    //     s = to_string(num);
    //     bool ok = true;
    //     for(int i = 0; i < s.size(); i++){
    //         if(s[i] != '7'){
    //             ok = false;
    //             break;
    //         }
    //     }
    //     if(ok){
    //         cout << s.size() << endl;
    //         return 0; 
    //     }
    //     tmp++;
    //     bai += 10;
    //     //cout << bai << endl;
    // }
    // cout << -1 << endl;

    ll k;
    cin >> k;
    ll div = 7;
    vector<int> num(k+10, -1);
    int c = 0;
    for(int i = 0; i < k+1; i++){
        //cout << "div; " << div << endl;
        
        if(div % k == 0){
            cout << i+1 << endl;
            return 0;
        }
        if(num[div] != -1){
            cout << -1 << endl;
            return 0;
        }
        num[div%k] = i+1;
        div = ((div*10)+7)%k;
    }
    return 0;
}