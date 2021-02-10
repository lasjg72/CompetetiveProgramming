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
    int n, x;
    cin >> n >> x;
    vector<int> l(n, 0), s(n+1, 0);
    int ans = 1;
    for(int i = 0; i< n; i++){
        cin >> l[i];
        s[i+1] = s[i] + l[i];
        if(s[i+1] <= x) ans++;
    }
    cout << ans << endl;
    return 0;
}