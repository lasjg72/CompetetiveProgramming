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
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if((a-b)%3 != 0 && (b-c)%3 != 0 && (a-c)%3 != 0){
            cout << -1 << endl;
            continue;
        }
        int ans = 1001001001;
        if((a-b)%3 == 0){
            int num = abs(a-b)/3;
            if(c < num) num += (num-c);
            if(a > b){
                num += a-num;
            }else{
                num += b-num;
            }
            ans = min(ans, num);
        }
        if((b-c)%3 == 0){
            int num = abs(b-c)/3;
            if(a < num) num += (num-a);
            if(b > c){
                num += b-num;
            }else{
                num += c-num;
            }
            ans = min(ans, num);
        }
        if((a-c)%3 == 0){
            int num = abs(a-c)/3;
            if(b < num) num += (num-b);
            if(a > c){
                num += a-num;
            }else{
                num += c-num;
            }
            ans = min(ans, num);
        }
        cout << ans << endl;
    }
    return 0;
}