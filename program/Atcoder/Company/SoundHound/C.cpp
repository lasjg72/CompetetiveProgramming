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
    ll n, m, d;
    cin >> n >> m >> d;
    double ans;
    if(d == 0){
        ans = (double)1/n*(m-1);
    }else{
        ans = (double)2*(n-d)/(n*n)*(m-1);
    }
    printf("%.7f\n", ans);
    return 0;
}