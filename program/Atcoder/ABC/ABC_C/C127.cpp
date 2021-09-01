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
    vector<int> num(100005, 0);
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
        num[l]++;
        num[r+1]--;
    }
    int ans = 0;
    for(int i = 1; i <= 100000; i++){
        num[i] += num[i-1];
        if(num[i] == m) ans++;
    }
    cout << ans << endl;
    return 0;
}