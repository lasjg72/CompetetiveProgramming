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
    int n, m;
    cin >> n >> m;
    vector<P> a(m);
    for(int i = 0; i < m; i++){
        cin >> a[i].second >> a[i].first;
    }
    sort(a.begin(), a.end());
    int ans = 0, pos = 0;
    for(int i = 0; i < m; i++){
        //cout << "a: " << a[i].second << " b: " << a[i].first << endl;
        if(a[i].second >= pos){
            ans++;
            pos = a[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}