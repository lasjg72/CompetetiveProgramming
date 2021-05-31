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
    vector<P> a(n), c(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    for(int i = 0; i < n; i++){
        cin >> c[i].first >> c[i].second;
    }
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());
    int ans = 0;
    vector<bool> used(n);
    for(int i = 0; i < n; i++){
        int nx = c[i].first;
        int tar = n;
        int my = -1;
        for(int j = 0; j < n; j++){
            if(a[j].first < nx && a[j].second < c[i].second && my < a[j].second && !used[j]){
                tar = j;
                my = max(my, a[j].second);
            }
        }
        used[tar] = true;
        if(tar != n) ans++;
    }
    cout << ans << endl;
    return 0;
}