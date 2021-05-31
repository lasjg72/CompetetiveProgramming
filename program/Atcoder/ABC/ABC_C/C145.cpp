#include <iostream>
#include <numeric>
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
    vector<double> x(n), y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    iota(a.begin(), a.end(), 0);
    double tot = 0;
    do{
        for(int i = 0; i < n-1; i++){
            int n1 = a[i];
            int n2 = a[i+1];
            tot += sqrt((x[n1]-x[n2])*(x[n1]-x[n2])+(y[n1]-y[n2])*(y[n1]-y[n2]));
        }
    }while(next_permutation(a.begin(), a.end()));
    ll num = 1;
    for(int i = n; i >= 1; i--) num *= i;
    printf("%.7f\n", tot/num);
    return 0;
}