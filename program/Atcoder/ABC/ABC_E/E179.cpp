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
    ll n, x, m;
    cin >> n >> x >> m;
    vector<int> ord(m, -1);
    vector<int> a;
    ll num = x, pos = 0;
    ll tot = 0;
    while(ord[num] == -1){
        a.push_back(num);
        ord[num] = pos;
        tot += num;
        pos++;
        num = (num*num)%m;
    }
    int cyc = pos-ord[num];
    if(pos == 1 && ord[num] == 0){
        ll ans = n*x;
        cout << ans << endl;
        return 0;
    }
    ll s = 0;
    for(int i = ord[num]; i < pos; i++){
        s += a[i];
    }
    //cout << "cyc: " << cyc << " num: " << num << " ord[num]: " << ord[num] << endl; 
    ll ans = x;
    if(n <= pos){
        for(int i = 0; i < n-1; i++){
            x = (x*x)%m;
            ans += x;
        }
    }else{
        ans = 0;
        ans += tot;
        n -= pos;
        ans += (n/cyc)*s;
        n %= cyc;
        for(int i = 0; i < n; i++){
            ans += a[ord[num]+i];
        }
    }
    cout << ans << endl;
    return 0;
}