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
    string x;
    ll m;
    cin >> x >> m;
    int d = 0;
    for(int i = 0; i < x.size(); i++){
        d = max(d, x[i]-'0');
    }
    //cout << "d: " << d << endl;
    ll ans = 0;
    bool flag = false;
    if(x.size()== 1 && x[0]-'0' <= m){
        ans = m-d;
    }else{
        while(1){
            //cout << "ko" << endl;
            d++;
            ll tar = 0;
            ll si = 1;
            for(int i = x.size()-1; i >= 0; i--){
                int now = x[i]-'0';
                //tar += pow(d, i)*now;
                
                if(i == x.size()-1){
                for(int j = 0; j < i; j++){
                    if(m/d < si){
                        flag = true;
                        break;
                    } 
                    si *= d;
                    //cout << si << endl;
                }
                }else{
                    si /= d;
                }
                if(now!= 0){
                    if(m/now < si) flag = true;
                }
                if(flag) break;
                tar += si * now;
            }
            if(flag) break;
            if(tar <= m) ans++;
            else break;
        }
    }
    cout << ans << endl;
    return 0;
}