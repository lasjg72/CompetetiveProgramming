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
    int a, b, c;
    cin >> a >> b >> c;
    char ans;
    if(c%2 == 0){
        if(abs(a) < abs(b)){
            ans = '<';
        }else if(abs(a) > abs(b)){
            ans = '>';
        }else{
            ans = '=';
        }
    }else{
        if((a >= 0 && b >= 0) || (a <= 0 && b <= 0) || (a < 0 && b > 0)){
            if(a < b){
                ans = '<';
            }else if(a > b){
                ans = '>';
            }else{
                ans = '=';
            }
        }else if(a > 0 && b < 0){
            ans = '>';
        }
    }
    cout << ans << endl;
    return 0;
}