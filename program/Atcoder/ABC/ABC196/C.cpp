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
    ll n;
    cin >> n;
    ll tmp = n;
    ll tmp2 = n;
    int num = 1;
    while(tmp2 >= 10){
        tmp2 /= 10;
        num++;
    }
    ll ans = 0;
    //cout << num << endl;
    if(num%2){
        num /= 2;
        for(int i = 0; i < num; i++){
            ans += pow(10, (num-i))-pow(10, (num-i-1));
        }
        cout << ans << endl;
        return 0;
    }
    num /= 2;
    for(int i = 0; i < num; i++){
        if(i == 0) {
            if(num == 1){
                tmp /= 10;
                ll c = n-(tmp*10);
                if(tmp <= c) ans = tmp;
                else ans = tmp-1;
            }else{
                tmp /= pow(10, num);
                ll c = n-tmp*(pow(10, num));
                // cout << "tmp: " << tmp << endl;
                // cout << "c: " << c << endl;
                //cout << tmp << endl;
                if(tmp <= c){
                     if(tmp - pow(10, num-1) +1 > 0)
                     ans += tmp - pow(10, num-1) +1;
                     //cout << "ans: " << ans << endl;
                }
                else {
                    if(tmp - (pow(10, num-1)) + 1 > 0)
                    ans += tmp - (pow(10, num-1));
                }
            }
        }else{
            //cout << "ko: " << pow(10, (num-i))-pow(10, (num-i-1)) << endl;
            ans += pow(10, (num-i))-pow(10, (num-i-1));
            //cout << ans << endl;
        }
    }
    cout << ans << endl;
    return 0;
}