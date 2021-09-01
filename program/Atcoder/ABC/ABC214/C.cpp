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
    int n;
    cin >> n;
    vector<ll> s(n), t(n), ans(n, 0);
    priority_queue<P, vector<P>, greater<P>> p;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++){
        cin >> t[i];
        p.push({t[i], i});
    }
    ll time = p.top().first;
    for(int i = 0; i < n; i++){
        ll pos = p.top().second;
        //cout << "pos: " << pos << endl;
        p.pop();
        ll next = (pos+1)%n;
        ans[next] = min(t[pos]+s[pos], t[next]);
        if(t[pos]+s[pos] < t[next]){
            p.push({t[pos]+s[pos], next});
            t[next] = t[pos]+s[pos];
        }
        time += s[pos];
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}