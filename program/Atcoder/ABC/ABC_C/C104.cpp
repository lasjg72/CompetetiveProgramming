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
    int D, G;
    cin >> D >> G;
    vector<int> p(D), c(D);
    for(int i = 0; i < D; i++){
        cin >> p[i] >> c[i];
    }
    int ans = 1001001001;
    for(int bit = 0; bit < (1<<D); bit++){
        ll tot = 0;
        int num = 0, mx = 0;
        for(int i = 0; i < D; i++){
            if(bit & (1<<i)){
                tot += p[i]*100*(i+1)+c[i];
                num += p[i];
            }else{
                mx = i;
            }
        }
        if(tot >= G) ans = min(ans, num);
        else{
            for(int j = 0; j < p[mx]; j++){
                tot += 100*(mx+1);
                num++;
                if(tot >= G){
                    ans = min(ans, num);
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}