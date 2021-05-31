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
    vector<P> p(n);
    for(int i = 0; i < n; i++){
        int x, l;
        cin >> x >> l;
        p[i].first = x+l;
        p[i].second = x-l;
    }
    int ans = 0;
    int now = -1001001001;
    sort(p.begin(), p.end());
    for(int i = 0; i < n; i++){
        if(now <= p[i].second){
            ans++;
            now = p[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}