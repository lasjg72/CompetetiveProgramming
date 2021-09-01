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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), p(n+1, 0);
    vector<pair<int, int>> num;
    int ans = 0, tmp = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(p[a[i]] == 0) tmp++; 
        p[a[i]]++;
    }
    for(int i = 1; i <= n; i++){
        if(p[i] > 0) num.push_back(pair<int, int>(p[i], i));
    }
    sort(num.begin(), num.end());
    for(int i = 0; i < tmp-k; i++){
        ans += num[i].first;
    }
    cout << ans << endl;
    return 0;
}