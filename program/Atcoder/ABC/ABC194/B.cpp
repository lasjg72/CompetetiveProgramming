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
    vector<P> a(n), b(n);
    for(int i = 0; i < n; i++){
        int c, d;
        cin >> c >> d;
        a[i].first = c;
        a[i].second = i;
        b[i].first = d;
        b[i].second = i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a[0].second != b[0].second){
        cout << max(a[0].first, b[0].first) << endl;
    }else{
        int a1 = max(a[0].first, b[1].first);
        int a2 = max(a[1].first, b[0].first);
        int ans = min(a1, a2);
        cout << min(ans, a[0].first+b[0].first) << endl;
    }
    return 0;
}