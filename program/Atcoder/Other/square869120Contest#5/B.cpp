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
    vector<double> x(n+m), y(n+m), r(n);
    double ansr = 1001001001;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> r[i];
        ansr = min(r[i], ansr);
    }
    for(int i = 0; i < m; i++){
        cin >> x[n+i] >> y[n+i];
    }
    double ans = 1001001001;
    for(int i = 0; i < (n+m)-1; i++){
        double d;
        double now = 1001001001;
        for(int j = n; j < (n+m); j++){
            if(i == j) continue;
            d = sqrt(pow(x[i]-x[j], 2)+pow(y[i]-y[j], 2));
            if(i < n){
                now = min(now, min(d-r[i], r[i]));
            }else{
                now = min(now, d/2);
            }
        }
        ans = min(ans, now);
    }
    if(ans > ansr) ans = ansr;
    printf("%.7f\n", ans);
    return 0;
}