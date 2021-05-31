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
    int n, k;
    cin >> n >> k;
    priority_queue<P, vector<P>, greater<P>> q;
    for(int i = 0; i < n; i++){
        P p;
        cin >> p.first >> p.second;
        q.push(p);
    }
    ll ans = 0;
    while(k--){
        P p = q.top(); q.pop();
        ans += p.first;
        p.first += p.second;
        q.push(p);
    }
    cout << ans << endl;
    return 0;
}
