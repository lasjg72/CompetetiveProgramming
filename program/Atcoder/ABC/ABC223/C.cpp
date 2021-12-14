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
    vector<double> a(n), b(n);
    double tot = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        tot += a[i]/b[i];
    }
    tot /= 2;
    double ans = 0;
    //cout << "tot: " << tot << endl;
    for(int i = 0; i < n; i++){
        if(tot <= a[i]/b[i]){
            ans += b[i]*tot;
            break;
        }
        ans += a[i];
        tot -= a[i]/b[i];
        //cout << ans << endl;
    }
    printf("%.6f\n", ans);
    return 0;
}