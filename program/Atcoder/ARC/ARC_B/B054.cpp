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
double p;

double f(double x){
    return x + p/(pow(2, x/1.5)); 
}

int main()
{
    cin >> p;

    double ans = 1e18;
    double wa = -1e18;

    for(int i = 0; i < 200; i++){
        double mid1 = (wa*2+ans)/3;
        double mid2 = (wa+ans*2)/3;
        //cout << "fmid1: " << f(mid1) << endl;
        if(f(mid1) > f(mid2)){
            wa = mid1;
        }else{
            ans = mid2;
        }
        //cout << "ans: " << ans << endl;
    }
    if(ans < 0) ans = 0;
    //cout << "f: " << f(ans) << endl;
    double now = f(ans);
    printf("%.9lf\n", now);
    return 0;
}