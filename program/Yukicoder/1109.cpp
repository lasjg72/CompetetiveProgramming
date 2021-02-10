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
    int n;
    cin >> n;
    vector<int> t(n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
    int d = -1;
    int ans = -1;
    bool ok = false;
    for(int i = 0; i < 12; i++){
        d = i;
        //cout << "i: " << i << endl;
        for(int j = 0; j < n; j++){
            // cout << "j: " << j << endl;
            // cout << "t[j]: " << t[j] << endl;
            if( (t[j]) %12 == d % 12 || (t[j]) %12 == (d+2)%12 || (t[j]) %12 == (d+4)%12 || (t[j]) %12 == (d+5)%12 || (t[j]) %12 == (d+7)%12 || (t[j]) %12 == (d+9)%12 || (t[j]) %12 == (d+11)%12){
                continue;
            }else{
                d = -1;
                break;
            }
        }
        if(d == -1) continue;
        if(!ok){
            ok = true;
            ans = d;
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}