#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

int main()
{
    int n, k, r, s, p;
    cin >> n >> k >> r >> s >> p;
    string t;
    cin >> t;
    ll ans = 0;
    vector<int> past(n, 0);
    
    for(int i = 0 ; i< n;i++){
        if(i-k >= 0 && t[i-k] == t[i]){

            if(t[i] == 'r'  && past[i-k]==0){ 
                ans += p;
                past[i] = 1;
            }
            else if(t[i] == 'r' && past[i-k] == 1){
                continue;
            }

            if(t[i] == 's'  && past[i-k]==0){ 
                ans += r;
                past[i] = 1;
            }
            else if(t[i] == 's' && past[i-k] == 1){
                continue;
            }

            if(t[i] == 'p'  && past[i-k]==0){ 
                ans += s;
                past[i] = 1;
            }
            else if(t[i] == 'p' && past[i-k] == 1){
                continue;
            }

        }else{
            if(t[i] == 'r'){
                ans += p;
                past[i] = 1;
            }
            if(t[i] == 's'){
                ans += r;
                past[i] = 1;
            }
            if(t[i] == 'p'){
                ans += s;
                past[i] = 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}