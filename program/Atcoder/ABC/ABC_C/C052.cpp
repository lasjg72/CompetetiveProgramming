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
const int mod = 1e9+7;

int main()
{
    int n;
    cin >> n;
    map<int, ll> num;
    for(int j = n; j >= 2; j--){
        int tmp = j;
        for(int i = 2; i*i <= j; i++){
            while(tmp%i==0){
                num[i]++;
                tmp /= i;
            }
        }
        if(tmp != 1){
            num[tmp]++;
        }
    }
    int ans = 1;
    for(int i = 2; i <= n; i++){
        ans = (ans * (num[i]+1))%mod;
    }
    cout << ans << endl;
    return 0;
}