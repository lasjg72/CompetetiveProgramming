#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    ll ans = 0;
    map<int, int> tmp;
    for(int i = 0; i< n; i++){
        cin >> a[i];
        tmp[a[i]]++;
        ans += a[i];
    }
    int q;
    cin >> q;
    for(int i = 0; i< q; i++){
        int b, c;
        cin >> b >> c;

            ans += (c-b)*tmp[b];
            tmp[c] += tmp[b];
            tmp[b] = 0;
            cout << ans << endl;
    }
    
    return 0;
}