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
    ll k;
    cin >> n >> k;
    vector<int> num(100000, 0);
    int now = n;
    ll c = 0;
    while(num[now] == 0){
        num[now] = c;
        c++;
        int tmp = now;
        while(tmp > 0){
            now += (tmp%10);
            tmp /= 10;
        }
        now %= 100000;
    }
    c -= num[now];
    int ans;
    if(k >= num[now]) {
        k -= num[now];
        k %= c;
        ans = now;
    }else{
        ans = n;
        now = n;
    }
    for(int i = 0; i < k; i++){
        while(now > 0){
            ans += (now%10);
            now /= 10;
        }
        ans %= 100000;
        now = ans;
        //cout << "ans: " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}