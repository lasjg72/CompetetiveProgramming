#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n,0);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    sort(h.rbegin(), h.rend());
    long long ans = 0;
    for(int i = k; i < n ;i++){
        ans += h[i];
    }
    printf("%lu\n", ans);
    //cout << ans << endl;
    return 0;
}