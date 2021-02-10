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
    int n, t;
    cin >> n >> t;
    vector<int> a(n,0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> mx(n-1,0);
    mx[n-2] = a[n-1];
    for(int i = n-3; i >= 0; i--){
        mx[i] = max(mx[i+1], a[i+1]);
    }
    // for(int i = 0; i < n-1; i++){
    //     //cout << "mx: " << mx[i] << endl;
    // }
    map<int, int> mer;
    int tmp = 0, m = 0;
    for(int i = 0; i < n; i++){
        tmp = mx[i]-a[i];
        mer[tmp]++;
        m = max(m, tmp);
    }
    int ans = mer[m];
    cout << ans << endl;
    return 0;
}