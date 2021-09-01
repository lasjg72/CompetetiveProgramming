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
    int n, k;
    cin >> n >> k;
    double ans = 0;
    for(int i = 1; i <= n; i++){
        int now = i;
        double tmp = (double)1/n;
        while(now < k){
            tmp *= 0.5;
            now *= 2;
        }
        ans += tmp;
    }
    printf("%.10f\n", ans);
    return 0;
}