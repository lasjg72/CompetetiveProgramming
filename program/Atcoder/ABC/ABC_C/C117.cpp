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
    int n, m;
    cin >> n >> m;
    vector<int> x(m), dist(m-1);
    for(int i = 0; i < m; i++){
        cin >> x[i];
        //if(i != 0) dist[i-1] = x[i]-x[i-1];
    }
    sort(x.begin(), x.end());
    for(int i = 0; i < m-1; i++){
        dist[i] = x[i+1]-x[i];
    }
    sort(dist.begin(), dist.end());
    ll ans = 0;
    for(int i = 0; i < m-n; i++){
        ans += dist[i];
    }
    cout << ans << endl;
    return 0;
}