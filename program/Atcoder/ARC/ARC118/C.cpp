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
    int n;
    cin >> n;
    vector<bool> is_prime(10001, false);
    is_prime[0] = false;
    is_prime[1] = false;
    
    for(int i = 6*2; i <= 10000; i += 6){
        is_prime[i] = true;
    }
    for(int i = 10*2; i <= 10000; i += 10){
        is_prime[i] = true;
    }
    for(int i = 15*2; i <= 10000; i += 15){
        is_prime[i] = true;
    }
    // vector<ll> can;
    // for(int i = 2; i <= 10000; i++){
    //     if(is_prime[i]) can.push_back((ll)i);
    //     if((int)can.size() == n) break;
    // }
    // for(int i = 0; i < n; i++){
    //     ll ans = 1;
    //     for(int j = 0; j < n; j++){
    //         if(i == j) continue;
    //         ans *= can[j];
    //         cout << "ans: " << ans << "can: " << can[j] << endl;
    //     }
    //     break;
    //     cout << ans << " ";
    // }
    cout << 6 << " " << 10 << " " << 15 << " ";
    if(n == 3){
        cout << endl;
        return 0;
    }else{
        n -= 3;
        for(int i = 12; i <= 10000; i++){
            if(is_prime[i]){
                cout << i << " ";
                n--;
            }
            if(n == 0) break;
        }
    }
    cout << endl;
    return 0;
}