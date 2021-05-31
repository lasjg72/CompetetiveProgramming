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
using P = pair<ll, ll>;

int main()
{
    ll n, k;
    cin >> n >> k;
    priority_queue<P, vector<P>, greater<P>> q;
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        q.push({a, b});
    }
    while(!q.empty()){
        P now = q.top(); q.pop();
        if(now.second >= k){
            cout << now.first << endl;
            return 0;
        }else{
            k -= now.second;
        }
    }
    return 0;
}