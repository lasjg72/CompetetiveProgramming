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
        tot += a[i];
        a[i] *= n;
    }
    int ans = 0, now = abs(a[0]-tot);
    for(int i = 1; i < n; i++){
        //cout << abs(a[i]-tot) << endl;
        if(abs(a[i]-tot) < now){
            now = abs(a[i]-tot);
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
