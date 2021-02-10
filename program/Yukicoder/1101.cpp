#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main()
{
    ll v, t, p;
    cin >> v >> t >> p;
    ll now = 0, ans = 0, time = 0;
    while(now <= v){
        now++;
        if(time != 0){
            
        }
        if(time == 0){
            //cout << "susu" << endl;
            now--;
            time = t;
            ans++;
            continue;
        }else if(now == v && p > 0){
            //cout << "kamu" << endl;
            now = 0;
            p--;
            if(time != 0) time--;
            ans++;
            continue;
        }
        //cout << "tamaru" << endl;
        ans++;
        
        continue;
    }
    ans--;
    
    cout << ans << endl;
    return 0;
}