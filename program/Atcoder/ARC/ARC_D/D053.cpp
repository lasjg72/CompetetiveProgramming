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
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<P> p1, p2;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(a < b){
            p1.push_back(P(a, b));
        }else{
            p2.push_back(P(b, a));
        }
    }
    sort(p1.begin(), p1.end());
    sort(p2.rbegin(), p2.rend());
    ll ans = 0, now = 0;
    for(P p : p1){
        now += (ll)p.first;
        ans = max(ans, now);
        now -= (ll)p.second;
    }
    for(P p : p2){
        now += (ll)p.second;
        ans = max(ans, now);
        now -= (ll)p.first;
    }
    cout << ans << endl;
    return 0;
}