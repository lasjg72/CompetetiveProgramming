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
    vector<vector<ll>> num(1000001, vector<ll>());
    for(int i = 1; i <= 1000000; i++){
        int tmp = i;
        for(int j = 2; j*j <= tmp; j++){
            if(tmp%j != 0) continue;
            while(tmp%j==0){
                tmp /= j;
            }
            num[i].push_back(j);
        }
        if(tmp != 1) num[i].push_back(tmp);
    }
    vector<ll> euler(1000001, 0);
    for(int i = 2; i <= 1000000; i++){
        euler[i] = i;
        for(int j: num[i]){
            euler[i] = euler[i]*(j-1)/j;
        }
    }
    vector<ll> ans(1000001, 0);
    ans[1] = 2;
    for(int i = 2; i <= 1000000; i++){
        ans[i] = ans[i-1] + euler[i];
        //if(i <= 10) cout << "i: " << i << " euler[i]: " << euler[i] << " ans[i]: " << ans[i] << endl;
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}