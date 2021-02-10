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
    double n, m;
    cin >> n >> m;
    vector<double> a(m);
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    double tmp = 1e9+7;
    if(m == 0){
        cout << 1 << endl;
        return 0;
    }
    for(int i = 0; i < m-1; i++){
        if(a[i+1]-a[i]-1 != 0) tmp = min(tmp, a[i+1]-a[i]-1);
    }
    if(n != a[m-1]){
        tmp = min(tmp, n-a[m-1]);
    }
    if(a[0] != 1){
        tmp = min(tmp, a[0] - 1);
    }
    //cout << "tmp: " << tmp << endl;
    if(tmp == 1e9+7){
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < m-1; i++){
        double x = a[i+1]-a[i]-1;
        ans += ceil(x / tmp);
        //cout << ans << endl;
    }
    ans += ceil((a[0]-1) / tmp);
    ans += ceil((n-a[m-1]) / tmp);
    cout << (int) ans << endl;
    return 0;
}