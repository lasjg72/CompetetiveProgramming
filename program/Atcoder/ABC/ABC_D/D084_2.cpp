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

bool prime[100005];

int main()
{
    int q;
    cin >> q;
    for(int p = 2; p <= 100000; p++){
        prime[p] = true;
        for(int i = 2; i*i <= p; i++){
            if(p%i == 0 && p/i != 1){
                prime[p] = false;
                break;
            }
        }
    }
    vector<ll> num(100005, 0);
    for(int p = 2; p <= 100000; p++){
        if(prime[p] && prime[(p+1)/2]) {
            num[p] += num[p-1]+1;
            //cout << "p: " << p << endl;
        }
        else num[p] = num[p-1];
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        int ans = 0;
        if(prime[l] && prime[(l+1)/2]){
            ans = num[r]-num[l]+1;
        }else{
            ans = num[r]-num[l];
        }
        cout << ans << endl;
    }
    return 0;
}