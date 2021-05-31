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
    int n;
    cin >> n;
    vector<int> a(n);
    int tot = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        tot ^= a[i];
    }
    vector<int> ans(n, tot);
    for(int i = 0; i < n; i++){
        ans[i] ^= a[i];
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}